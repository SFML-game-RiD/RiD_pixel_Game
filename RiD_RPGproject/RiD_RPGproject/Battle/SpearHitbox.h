#pragma once
#include "SFML/Graphics.hpp"

namespace RTB
{
	class SpearHitbox
	{
	private:
		sf::RectangleShape _hitbox;
		sf::Sprite* _object;
		sf::Vector2f _offset;
		enum directions { up, left, down, right };
	public:
		SpearHitbox(sf::Sprite*& object);
		~SpearHitbox();

		//Checks if hitbox collides with another object's hitbox given as rectangle
		bool checkIntersection(const sf::FloatRect& rectangle);

		//Updates hitbox position
		void update(short direction);

		//Renders hitbox
		void render(sf::RenderTarget& window);
	};
}