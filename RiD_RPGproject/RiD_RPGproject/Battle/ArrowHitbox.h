#pragma once

#include "SFML/Graphics.hpp"

namespace RTB
{
	class ArrowHitbox
	{
	private:
		sf::RectangleShape _hitbox;
		sf::Sprite *_arrow = nullptr;
		enum directions { up, left, down, right };
	public:
		ArrowHitbox(sf::Sprite*& arrow);

		void update(short direction);

		void render(sf::RenderTarget& window);

		sf::RectangleShape& getHitbox();

	};
}