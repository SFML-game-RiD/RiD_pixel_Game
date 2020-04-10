#ifndef _CURSOR_H_
#define _CURSOR_H_
#include "SFML/Graphics.hpp"
#include "Obiect.h"

namespace MP
{
	class Cursor: public Obiect
	{
	private:
			
		sf::Vector2f _game_coord;

	public:

		void saveGameCoord(sf::Vector2f guiCoord);

		sf::Vector2f getGuiCoord();

		Cursor(sf::Texture* texturePtr);
	};
}
#endif // !_CURSOR_H_