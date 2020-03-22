#pragma once

#include "Character.h"


namespace RTB
{
	class Bot
		:public Character
	{
	private:
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
		HPBar* _hp_bar = nullptr;
	public:
		Bot(sf::Texture texture, short health_points);
		~Bot();

		//Sets bots position
		void setPosition(sf::Vector2f position);

		//Function responsible for all of the bots moves and behaviors
		const void update(sf::Time time);

		//Draws bots sprite
		void render(sf::RenderWindow& window);

		//Checks if character is alive
		bool isAlive();

		//Gets bots position
		sf::Vector2f getPosition();

		sf::RectangleShape getHitbox();

		void subtractHP(short value);
	};
}