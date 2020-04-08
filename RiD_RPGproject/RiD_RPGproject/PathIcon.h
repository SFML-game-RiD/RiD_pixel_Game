#ifndef _PATHICON_H_
#define _PATHICON_H_
#include "Obiect.h" 

namespace MP
{
	class PathIcon :public Obiect
	{
	public:
		
		PathIcon(sf::Texture* texturePtr,sf::Vector2f spawnCoord);
	};
}
#endif // !_PATHICON_H_
