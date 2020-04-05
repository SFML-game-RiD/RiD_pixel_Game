#ifndef _MAPANIMATION_H_
#define _MAPANIMATION_H_
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

		std::vector<sf::IntRect> _obiect_rectangle_array;

		int _current_sprite;

		void _set_obiect_texture(sf::Texture * texture);

		void _set_obiect_texture_rect(sf::IntRect& textureRect);

		void _get_rectangle_array(int columns, int rows, int squareLength);

	public:

		void setObiectSpritePosition(int x, int y);

		void setObiectSpritePosition(sf::Vector2f coord);

		sf::Sprite& getObiectSprite();

		void loadObiectTextures(sf::Texture* texturePtr, int columns, int rows, int squareLength);

		void changeSprite(int spriteNumber);

		const std::vector<sf::IntRect>& getOryginalArray();

		int getCurrentSprite();

		void setNextSprite(int from, int to);

		void setScale(float x, float y);

		void setOrigin(int x, int y);

	};
}
#endif