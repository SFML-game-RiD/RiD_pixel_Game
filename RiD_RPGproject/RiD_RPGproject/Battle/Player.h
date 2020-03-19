#pragma once

#include "Character.h"


namespace RTB
{
	class Player
		:Character
	{
	private:
		sf::Texture _texture;
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
		HPBar* _hp_bar = nullptr;
	public:
		Player(sf::Texture texture);
		~Player();

		//Sets player position
		void setPosition(sf::Vector2f position);

		//Function responsible for all of the player moves and behaviors
		void update(sf::Time time);

		//Draws player sprite
		void render(sf::RenderWindow& window);

		//Checks if character is alive
		bool isAlive();

		//Gets player position
		sf::Vector2f getPosition();
	};
}