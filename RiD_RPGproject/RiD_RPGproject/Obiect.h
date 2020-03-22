#ifndef _OBIECT_H_
#define _OBIECT_H_

#include <utility>
#include <SFML/Graphics.hpp>

namespace MP
{
	class Obiect
	{
	private:

		std::pair<int, int> _objCoord;

	public:

		sf::Time objSleepTime;
		sf::Texture objTexture;
		sf::Sprite objSprite;
		sf::IntRect objRectangle;

		void setObiectCoord(int x, int y);
		std::pair<int,int> getObiectCoord();
	};
}
#endif