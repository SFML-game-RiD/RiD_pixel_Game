#ifndef _MAPANIMATION_H_
#define _MAPANIMATION_H_
#include <vector>
#include "Engine/ConfigurationLoader.h"
#include <SFML/Graphics.hpp>

namespace MP
{
	class MapAnimation
	{
	private:

		sf::Texture objTexture;
		sf::Sprite objSprite;
		sf::IntRect objRectangle;
		std::vector<sf::IntRect> _obiect_rectangle_array;
		int currentSprite;


		void setObiectTexture(sf::Texture &texture);

		void setObiectTextureRect(sf::IntRect &textureRect);

		void getRectangleArray(int columns, int rows, int squareLength);

	public:

	void setObiectSpritePosition(int x, int y);

	void setObiectSpritePosition(std::pair<int,int> coord);

	 sf::Sprite& getObiectSprite();
	
	void loadObiectTextures(std::string texturePath, int columns, int rows, int squareLength);

	void changeSprite(int spriteNumber);

	const std::vector<sf::IntRect>& getOryginalArray();

	int getCurrentSprite();

	};
}
#endif