#ifndef LAND_H
#define LAND_H

#include "Obiect.h"

namespace MP
{
	class Land:public Obiect
	{
	private:

	public:

		Land(sf::Texture* texturePtr, int x,int y);

		Land( int x,int y); //Is only use for path creator, stores coordination.

		void update();
		void render(sf::RenderWindow &mainWindow);
	};
}
#endif // !_LAND_H_