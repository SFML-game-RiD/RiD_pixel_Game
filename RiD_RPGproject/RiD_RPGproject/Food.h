#ifndef _FOOD_H_
#define _FOOD_H_
#include "Item.h"

namespace MP
{
	class Food :public Item
	{
	private:

	public:

		Food();

		Food(sf::Texture* texturePtr,sf::Font& aFont);

		 void setItemAmount(unsigned int newItemAmount);

		 unsigned int& getItemAmount();

		 void setItemPosition(sf::Vector2f itemPosition);

		 void drawItem(sf::RenderWindow& mainWindow);
	};
}
#endif