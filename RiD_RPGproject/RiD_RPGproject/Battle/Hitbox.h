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

		void update();

		void render(sf::RenderTarget& window);
	};
}