#ifndef IRON_H
#define IRON_H
#include "Item.h"

namespace MP
{
	class Iron :public Item
	{
	private:

	public:
		Iron();
		Iron(sf::Texture* texturePtr, sf::Font& aFont);

		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);
	};

}
#endif