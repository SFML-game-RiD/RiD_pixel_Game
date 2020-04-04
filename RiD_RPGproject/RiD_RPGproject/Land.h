#ifndef _LAND_H_
#define _LAND_H_

#include "StaticObiect.h"

namespace MP
{
	class Land:public StaticObiect
	{
	private:

	public:

		Land(sf::Texture* texturePtr, int x,int y);

		Land( int x,int y); //Is only use for path creator, stores coordination.

	};
}
#endif // !_LAND_H_