#pragma once

#include "Swordsman.h"

namespace RTB
{
	void Swordsman::_dealSwordDamage(std::list<std::shared_ptr<Character>>& list_of_bots)
	{
		for (std::list<std::shared_ptr<Character>>::iterator iterator = list_of_bots.begin();//Iterates through list of bots...
			iterator != list_of_bots.end(); iterator++)
		{
			if ((*iterator)->isAlive() && _sword_hitbox->checkIntersection((*iterator)->getHitbox().getGlobalBounds()) == true)//checks if sword intersected one of them...
			{
				(*iterator)->subtractHP(10);//and subtracts hp
			}
		}
		_movement->notReadyToDealSwordDamage();
	}
	sf::Vector2i Swordsman::_isoTo2D(sf::Vector2f position)
	{
		return sf::Vector2i(((2 * position.y + position.x) / 2) / 25, ((2 * position.y - position.x) / 2) / 25);
	}

	std::list<std::shared_ptr<Character>>::iterator Swordsman::_selectRandomEnemy(std::list<std::shared_ptr<Character>>::iterator start, std::list<std::shared_ptr<Character>>::iterator end)
	{
		unsigned seed = static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		std::mt19937 gen(seed);
		std::uniform_int_distribution<int> dis(0, std::distance(start, end) - 1);
		std::advance(start, dis(gen));
		return start;
	}

	Swordsman::Swordsman(sf::Texture texture, short health_points, std::vector<std::vector<AI::PathNode>>& walkable_area)
	{
		_path_generator = new AI::RTBPathGenerator(walkable_area);
		_health_points = health_points;
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 24.f, 46.f }, { -12.f,-16.f });
		_sword_hitbox = new SwordHitbox(_character_sprite);
		_hp_bar = new HPBar(_character_sprite, _health_points);
		_is_alive = true;
		_is_enemy_choosen = false;
		_speed = 0.8f;
	}

	Swordsman::~Swordsman()
	{
		delete _movement;
		delete _hitbox;
		delete _character_sprite;
		delete _hp_bar;
		delete _sword_hitbox;
		delete _path_generator;
	}

	void Swordsman::setPosition(sf::Vector2f position)
	{
		_movement->setSpritePosition(position);
	}

	void Swordsman::update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects,
		std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderWindow& window)
	{
		_position = _movement->getSprite().getPosition();
		if (!_movement->isAttackTriggered())
		{
			if (_is_enemy_choosen)
			{
				_current_enemy_position = _isoTo2D((*_choosen_enemy)->getPosition());
				if (_current_path == nullptr)
				{
					_path_generator->findPath(_isoTo2D(_position), _isoTo2D((*_choosen_enemy)->getPosition()));
					_current_path = _path_generator->getPath();
					_half_way = _path_generator->getMiddle();
					_tmp_current_path = _current_path;
					_end_path_position = _current_enemy_position;
				}
				else if (_current_enemy_position != _end_path_position && _tmp_current_path == _half_way)
				{
					delete_path();
					_path_generator->findPath(_isoTo2D(_position), _isoTo2D((*_choosen_enemy)->getPosition()));
					_current_path = _path_generator->getPath();
					_half_way = _path_generator->getMiddle();
					_tmp_current_path = _current_path;
					_end_path_position = _current_enemy_position;
				}
				else if (_tmp_current_path->getPNext())
				{
					if (_tmp_current_path->getPNext()->getPosition().x > _isoTo2D(_position).x &&
						_tmp_current_path->getPNext()->getPosition().y < _isoTo2D(_position).y)
					{
						_movement->walkingRight(time, _speed, -_speed);
					}
					else if (_tmp_current_path->getPNext()->getPosition().x < _isoTo2D(_position).x &&
						_tmp_current_path->getPNext()->getPosition().y < _isoTo2D(_position).y)
					{
						_movement->walkingLeft(time, -_speed, -_speed);
					}
					else if (_tmp_current_path->getPNext()->getPosition().x < _isoTo2D(_position).x &&
						_tmp_current_path->getPNext()->getPosition().y > _isoTo2D(_position).y)
					{
						_movement->walkingLeft(time, -_speed, _speed);
					}
					else if (_tmp_current_path->getPNext()->getPosition().x > _isoTo2D(_position).x &&
						_tmp_current_path->getPNext()->getPosition().y > _isoTo2D(_position).y)
					{
						_movement->walkingRight(time, _speed, _speed);
					}
					else if (_tmp_current_path->getPNext()->getPosition().x > _isoTo2D(_position).x)
					{
						_movement->walkingRight(time, _speed, 0.0f);
					}

					else if (_tmp_current_path->getPNext()->getPosition().x < _isoTo2D(_position).x)
					{
						_movement->walkingLeft(time, -_speed, 0.0f);
					}

					else if (_tmp_current_path->getPNext()->getPosition().y < _isoTo2D(_position).y)
					{
						_movement->walkingUp(time, 0.0f, -_speed);
					}

					else if (_tmp_current_path->getPNext()->getPosition().y > _isoTo2D(_position).y)
					{
						_movement->walkingDown(time, 0.0f, _speed);
					}
					else
						_movement->idle(time);

					if (_tmp_current_path->getPNext()->getPosition() == _isoTo2D(_position))
						_tmp_current_path = _tmp_current_path->getPNext();
				}
			}
			else
			{
				_choosen_enemy = _selectRandomEnemy(list_of_bots.begin(), list_of_bots.end());
				_current_enemy_position = _isoTo2D((*_choosen_enemy)->getPosition());
				_is_enemy_choosen = true;

			}
		}
		if (!(*_choosen_enemy)->isAlive())
			_is_enemy_choosen = false;
		else
		{
			int distance;
			distance = sqrt(pow((_isoTo2D((*_choosen_enemy)->getPosition()).x - _isoTo2D(_position).x), 2) + pow((_isoTo2D((*_choosen_enemy)->getPosition()).y - _isoTo2D(_position).y), 2));
			if (distance < 2)
				_movement->triggerAttack();
		}
		_hitbox->update();
		_hp_bar->update();

		if (_movement->isDeathTriggered())
		{
			delete_path();
			_movement->death(time);
			if (_movement->isDeathTriggered() == false)
				_is_alive = false;
		}
	}

	void Swordsman::render(sf::RenderWindow& window)
	{
		window.draw(_movement->getSprite());
		_hitbox->render(window);
		_hp_bar->render(window);
	}

	bool Swordsman::isAlive()
	{
		return _is_alive;
	}
	sf::Vector2f Swordsman::getPosition()
	{
		return _movement->getSprite().getPosition();
	}

	sf::RectangleShape Swordsman::getHitbox()
	{
		return _hitbox->getRectangle();
	}

	void Swordsman::dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window)
	{
		if (_movement->isAttackTriggered())
		{
			_movement->swordSwing(time);
			_sword_hitbox->update(_movement->getDirection());
			_sword_hitbox->render(window);
		}
		if (_movement->isReadyToDealSwordDamage())
			this->_dealSwordDamage(list_of_bots);
	}

	void Swordsman::subtractHP(short value)
	{
		_health_points -= value;
		_hp_bar->shortenBar(value);
		if (_health_points < 1)
		{
			_movement->triggerDeath();
		}

	}

	void Swordsman::delete_path()
	{
		AI::PathNode* iterator = _current_path;

		while (iterator != 0)
		{
			_current_path = iterator->getPNext();
			delete iterator;
			iterator = _current_path;
		}

		delete _current_path;
	}

	void Swordsman::deadBody(sf::RenderWindow& window)
	{
		_movement->dead();
		window.draw(_movement->getSprite());
	}
}