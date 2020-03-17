#pragma once

#include "../Engine/Movement.h"

namespace RTB
{
	class Character
	{
	private:
		sf::Sprite _character_sprite;
	protected:
		short _health_points;
		short arrows;
		short damage;
		sf::Vector2f position;
	public:
		//Sets character position
		virtual void setPosition(float x, float y) = 0;

		//Function responsible for all of the moves
		virtual void movement(sf::Time time) = 0;

		//Draws character sprite
		virtual void render(sf::RenderWindow& window) = 0;
	};
}