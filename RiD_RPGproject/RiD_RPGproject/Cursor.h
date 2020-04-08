#ifndef _CURSOR_H_
#define _CURSOR_H_
#include "SFML/Graphics.hpp"
#include "Obiect.h"

namespace MP
{
	class Cursor: public Obiect
	{
	private:
			

	public:

		Cursor(sf::Texture* texturePtr);
	};
}
#endif // !_CURSOR_H_