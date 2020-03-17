#pragma once

#include "Character.h"
#include "../Engine/Movement.h"

namespace RTB
{
	class Player
		:Character
	{
	private:
		RiD::Movement _movement;
	public:
		Player(RiD::Movement &movement);

		//Sets player position
		void setPosition(float x, float y);

		//Function responsible for all of the player moves
		void movement(sf::Time time);

		//Draws player sprite
		void render(sf::RenderWindow& window);

		//Gets player position
		sf::Vector2f getPosition();
	};
}