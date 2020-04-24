#ifndef SWORDSMAN_H
#define SWORDSMAN_H
#include "Item.h"

namespace MP
{
	class Swordsman :public Item
	{
	private:

	public:

		Swordsman();
		Swordsman(sf::Texture* texturePtr,sf::Font& aFont);
	
		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);
	};
}
#endif 