#ifndef LAND_H
#define LAND_H

#include "StaticObiect.h"

namespace MP
{
	class Land:public StaticObiect
	{
	private:

	public:

		Land(sf::Texture* texturePtr, int x,int y);

		Land( int x,int y); //Is only use for path creator, stores coordination.

		void update();
		void render();
	};
}
#endif // !_LAND_H_