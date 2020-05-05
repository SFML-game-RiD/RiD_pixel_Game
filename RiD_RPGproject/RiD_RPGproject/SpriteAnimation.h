#pragma once
#include <vector>
#include "Engine/ConfigurationLoader.h"
#include <SFML/Graphics.hpp>

namespace MP
{
	class SpriteAnimation
	{
	private:

		sf::Texture *_obj_texture;

		sf::Sprite _obj_sprite;

		sf::IntRect _obj_rectangle;

		sf::Color _obj_color;

		std::vector<sf::IntRect> _object_rectangle_array;

		int _current_sprite;

		void _set_object_texture_rect(sf::IntRect& textureRect);

		void _get_rectangle_array(int columns, int rows, int squareLength);

	public:

		void loadObjectTextures(sf::Texture* texturePtr, int columns, int rows, int squareLength);
		void changeSprite(int spriteNumber);
	
		void setObjectSpritePosition(int x, int y);
		void setObjectSpritePosition(sf::Vector2f coord);
		void setNextSprite(int from, int to);
		void setScale(float x, float y);
		void setOrigin(int x, int y);
		void setColor(sf::Color newColor);
	
		sf::Sprite& getObjectSprite();
		sf::Vector2f getScale();
		int getCurrentSprite();
		const std::vector<sf::IntRect>& getOryginalArray();
	

	
	};
}