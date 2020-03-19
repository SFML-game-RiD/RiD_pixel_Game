#include "Hitbox.h"
#pragma once

namespace RTB
{
	Hitbox::Hitbox(sf::Sprite*& object, sf::Vector2f size, sf::Vector2f offset):
		_object(object), _offset(offset)
	{
		_hitbox.setPosition(_object->getPosition().x + offset.x, _object->getPosition().y + offset.y);
		_hitbox.setSize(size);
		_hitbox.setFillColor(sf::Color::Transparent);
		_hitbox.setOutlineThickness(1.f);
		_hitbox.setOutlineColor(sf::Color::Green);
	}

	Hitbox::~Hitbox()
	{
		_object = nullptr;
	}

	bool Hitbox::checkIntersection(const sf::FloatRect& rectangle)
	{
		return _hitbox.getGlobalBounds().intersects(rectangle);
	}

	void Hitbox::update()
	{
		_hitbox.setPosition(_object->getPosition().x + _offset.x, _object->getPosition().y + _offset.y);
	}

	void Hitbox::render(sf::RenderTarget& window)
	{
		window.draw(_hitbox);
	}
}