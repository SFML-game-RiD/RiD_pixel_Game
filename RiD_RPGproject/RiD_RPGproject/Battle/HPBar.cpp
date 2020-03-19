#pragma once

#include "HPBar.h"

namespace RTB
{
	HPBar::HPBar(sf::Sprite*& object): _object(object)
	{
		_hp_background.setPosition(_object->getPosition().x, _object->getPosition().y);
		_hp_background.setSize(sf::Vector2f(34.f, 5.f));
		_hp_background.setFillColor(sf::Color::Red);
		_hp_bar.setPosition(_object->getPosition().x, _object->getPosition().y);
		_hp_bar.setSize(sf::Vector2f(34.f, 5.f));
		_hp_bar.setFillColor(sf::Color::Green);
	}

	void HPBar::update()
	{
		_hp_background.setPosition(_object->getPosition().x - 18.f, _object->getPosition().y - 23.f);
		_hp_bar.setPosition(_object->getPosition().x - 18.f, _object->getPosition().y - 23.f);
	}

	void HPBar::render(sf::RenderTarget& window)
	{
		window.draw(_hp_background);
		window.draw(_hp_bar);
	}
}