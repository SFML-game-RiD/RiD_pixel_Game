#pragma once

#include <utility>
#include <SFML/Graphics.hpp>

namespace MP
{
	class Obiect
	{
	private:

		std::pair<int, int> _objCoord;

	public:

		sf::Texture objTexture;
		sf::Sprite objSprite;
		sf::IntRect objRectangle;

		void setObiectCoord(int x, int y);
		std::pair<int,int> getObiectCoord();
	};
}
