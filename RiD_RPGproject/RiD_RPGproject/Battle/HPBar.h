#pragma once

#include "SFML/Graphics.hpp"

namespace RTB
{
	class HPBar
	{
	private:
		sf::RectangleShape _hp_bar, _hp_background;
		sf::Sprite* _object;
		sf::Vector2f _offset;
	public:
		HPBar(sf::Sprite*& object);

		void update();

		void render(sf::RenderTarget& window);
	};
}