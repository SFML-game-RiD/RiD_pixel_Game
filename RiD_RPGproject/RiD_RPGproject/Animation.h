#ifndef MAPANIMATION_H
#define MAPANIMATION_H
#include <vector>
#include "Engine/ConfigurationLoader.h"
#include <SFML/Graphics.hpp>

namespace MP
{
	class Animation
	{
	private:

		sf::Texture *_obj_texture;

		sf::Sprite _obj_sprite;

		sf::IntRect _obj_rectangle;

		sf::Color _obj_color;

		std::vector<sf::IntRect> _obiect_rectangle_array;

		int _current_sprite;

		void _set_obiect_texture(sf::Texture * texture);

		void _set_obiect_texture_rect(sf::IntRect& textureRect);

		void _get_rectangle_array(int columns, int rows, int squareLength);

	public:

		void loadObiectTextures(sf::Texture* texturePtr, int columns, int rows, int squareLength);
		void changeSprite(int spriteNumber);
	
		void setObiectSpritePosition(int x, int y);
		void setObiectSpritePosition(sf::Vector2f coord);
		void setNextSprite(int from, int to);
		void setScale(float x, float y);
		void setOrigin(int x, int y);
		void setColor(sf::Color newColor);
	
		sf::Sprite& getObiectSprite();
		sf::Vector2f getScale();
		int getCurrentSprite();
		const std::vector<sf::IntRect>& getOryginalArray();
	

	
	};
}
#endif