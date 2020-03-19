#pragma once

#include "Character.h"
#include "../Engine/Movement.h"
#include "Hitbox.h"

namespace RTB
{
	class Player
		:Character
	{
	private:
		sf::Sprite *_player;
		sf::Texture _texture;
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
	public:
		Player(sf::Texture texture);
		~Player();

		//Sets player position
		void setPosition(sf::Vector2f position);

		//Function responsible for all of the player moves
		void movement(sf::Time time);

		//Draws player sprite
		void render(sf::RenderWindow& window);

		//Gets player position
		sf::Vector2f getPosition();
	};
}