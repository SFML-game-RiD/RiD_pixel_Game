#pragma once

#include "Archer.h"

namespace RTB
{
	std::list<std::shared_ptr<Character>>::iterator Archer::_selectRandomEnemy(std::list<std::shared_ptr<Character>>::iterator start, std::list<std::shared_ptr<Character>>::iterator end)
	{
		unsigned seed = static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		std::mt19937 gen(seed);
		std::uniform_int_distribution<int> dis(0, std::distance(start, end) - 1);
		std::advance(start, dis(gen));
		return start;
	}

	void Archer::_dealBowDamage(std::list<std::shared_ptr<Character>>& list_of_bots)
	{
		for (std::list<std::shared_ptr<Character>>::iterator iterator = list_of_bots.begin();
			iterator != list_of_bots.end(); iterator++)
		{
			if ((*iterator)->isAlive() && _arrows->isFlying() && checkOrientedCollision((*iterator)->getHitbox(), _arrows->getHitbox()))
			{
				(*iterator)->subtractHP(1);
			}
		}
	}

	sf::Vector2i Archer::_findAttackPosition(int width, int height)
	{
		unsigned short index;
		sf::Vector2i enemy_attack_positions[4];
		int distances[4];
		int i = _current_enemy_position.x, j = _current_enemy_position.y;
		while (i > 0 && j > 0 && abs(_current_enemy_position.x-j) < 6 && abs(_current_enemy_position.x - i) < 6)
		{
			i--;
			j--;
		}
		enemy_attack_positions[0] = sf::Vector2i(i, j);
		distances[0] = _path_generator->distance(_isoTo2D(_position), sf::Vector2i(i, j));
		i = _current_enemy_position.x, j = _current_enemy_position.y;
		while (i > 0 && j < width && abs(_current_enemy_position.x - j) < 6 && abs(_current_enemy_position.x - i) < 6)
		{
			i--;
			j++;
		}
		enemy_attack_positions[1] = sf::Vector2i(i, j);
		distances[1] = _path_generator->distance(_isoTo2D(_position), sf::Vector2i(i, j));
		i = _current_enemy_position.x, j = _current_enemy_position.y;
		while (i < height && j < width && abs(_current_enemy_position.x - j) < 6 && abs(_current_enemy_position.x - i) < 6)
		{
			i++;
			j++;
		}
		enemy_attack_positions[2] = sf::Vector2i(i, j);
		distances[2] = _path_generator->distance(_isoTo2D(_position), sf::Vector2i(i, j));
		i = _current_enemy_position.x, j = _current_enemy_position.y;
		while (i < height && j >0 && abs(_current_enemy_position.x - j) < 6 && abs(_current_enemy_position.x - i) < 6)
		{
			i++;
			j--;
		}
		enemy_attack_positions[3] = sf::Vector2i(i, j);
		distances[3] = _path_generator->distance(_isoTo2D(_position), sf::Vector2i(i, j));
		index = 0;
		for (unsigned short i = 0; i < 4; i++)
		{
			if (distances[i] < distances[index])
				index = i;
		}
		return enemy_attack_positions[index];
	}

	Archer::Archer(sf::Texture texture, short health_points, sf::Texture& arrow_texture, std::vector<std::vector<AI::PathNode>>& walkable_area)
	{
		_path_generator = new AI::RTBPathGenerator(walkable_area);
		_health_points = health_points;
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 24.f, 46.f }, { -12.f,-16.f });
		_hp_bar = new HPBar(_character_sprite, _health_points);
		_arrows = new Arrow(_character_sprite, arrow_texture);
		_is_alive = true;
		_is_enemy_choosen = false;
		_speed = 0.8f;
	}

	Archer::~Archer()
	{
		delete _movement;
		delete _hitbox;
		delete _character_sprite;
		delete _hp_bar;
		delete _arrows;
		delete _path_generator;
	}

	void Archer::update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects,
		std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderWindow& window)
	{
		_position = _movement->getSprite().getPosition();
		if (!_movement->isShotTriggered())
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
			if (distance < 8 && !_arrows->isFlying())
			{
				_shot_destination = { (int)(*_choosen_enemy)->getPosition().x, (int)(*_choosen_enemy)->getPosition().y };
				_movement->triggerShot();
			}
		}
		_hitbox->update();
		_hp_bar->update();
		if (_movement->isDeathTriggered())
		{
			_movement->death(time);
			if (_movement->isDeathTriggered() == false)
				_is_alive = false;
		}
	}

	void Archer::dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window)
	{
		if (_movement->isShotTriggered())
		{
			_position = _character_sprite->getPosition();
			_arrows_count--;
			if (_shot_destination.x - _position.x > 0 && abs(_shot_destination.x - _position.x) > abs(_shot_destination.y - _position.y))
				_direction = right;
			else if (_shot_destination.x - _position.x < 0 && abs(_shot_destination.x - _position.x)> abs(_shot_destination.y - _position.y))
				_direction = left;
			else if (_shot_destination.y - _position.y > 0 && abs(_shot_destination.x - _position.x) < abs(_shot_destination.y - _position.y))
				_direction = down;
			else if (_shot_destination.y - _position.y < 0 && abs(_shot_destination.x - _position.x) < abs(_shot_destination.y - _position.y))
				_direction = up;
			_movement->bowShot(time,_direction);
			_arrows->update();
		}
		if (_movement->isReadyToShotArrow())
		{
			_arrows->fly(time, window, _shot_destination);
			this->_dealBowDamage(list_of_bots);
		}

		if (_arrows->isFlying() == false)
			_movement->notReadyToShotArrow();
	}

	void Archer::render(sf::RenderWindow& window)
	{
		window.draw(_movement->getSprite());
		_hitbox->render(window);
		_hp_bar->render(window);
	}

	void Archer::delete_path()
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

	void Archer::deadBody(sf::RenderWindow& window)
	{
		_movement->dead();
		window.draw(_movement->getSprite());
	}
}