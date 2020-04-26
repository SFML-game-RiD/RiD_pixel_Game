#ifndef PLACES_H
#define PLACES_H
#include "ActiveObiect.h"

namespace MP
{
	class Places:public ActiveObiect
	{


	public:
		Places();

		void update();
		void render(sf::RenderWindow& mainWindow);
	};
}
#endif // !_PLACES_H_