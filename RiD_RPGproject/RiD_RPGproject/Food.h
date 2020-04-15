#ifndef FOOD_H
#define FOOD_H
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