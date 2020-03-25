#pragma once

#include "../Engine/Movement.h"
#include "Hitbox.h"
#include "HPBar.h"

namespace RTB
{
	class Character
	{
	protected:
		sf::Sprite* _character_sprite;
		short _health_points;
		short _arrows;
		short _damage;
		sf::Vector2f _position;
		bool _is_alive;
	public:

		//Sets character position
		virtual void setPosition(sf::Vector2f position) = 0;

		//Function responsible for all of the moves
		//virtual void update(sf::Time time) = 0;

		//Draws character sprite
		virtual void render(sf::RenderWindow& window) = 0;

		//Checks if character is alive
		virtual bool isAlive() = 0;

		//Gets character position
		virtual sf::Vector2f getPosition() = 0;
	};
}