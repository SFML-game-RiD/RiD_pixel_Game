#pragma once
#include <utility>
#include <SFML/Graphics.hpp>
namespace MP
{
	class Obiect
	{
	public:

		std::pair<int, int> objCoord;
		sf::Texture objTexture;
		sf::Sprite objSprite;
		sf::IntRect objRectangle;
	};
}
