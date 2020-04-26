#ifndef PATHICON_H
#define PATHICON_H
#include "Obiect.h" 

namespace MP
{
	class PathIcon :public Obiect
	{
	public:
		
		PathIcon(sf::Texture* texturePtr,sf::Vector2f spawnCoord);

		void update();

		void render(sf::RenderWindow& mainWindow);
	};
}
#endif // !_PATHICON_H_
