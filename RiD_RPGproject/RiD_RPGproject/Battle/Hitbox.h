#pragma once

#include "SFML/Graphics.hpp"

namespace RTB
{
	class Hitbox
	{
	private:
		sf::RectangleShape _hitbox;
		sf::Sprite *_object;
		sf::Vector2f _offset;
	public:
		Hitbox(sf::Sprite *&object, sf::Vector2f size, sf::Vector2f offset);
		~Hitbox();

		//Checks if hitbox collides with another object's hitbox given as rectangle
		bool checkIntersection(const sf::FloatRect& rectangle);

		//Updates hitbox position
		void update();

		//Renders hitbox on the window
		void render(sf::RenderTarget& window);

		//Returns rectangle of hitbox
		sf::RectangleShape& getRectangle();
	};
}