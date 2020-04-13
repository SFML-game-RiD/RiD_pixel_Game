#ifndef _IRON_H_
#define _IRON_H_
#include "Item.h"

namespace MP
{
	class Iron :public Item
	{
	private:

	public:
		Iron();
		Iron(sf::Texture* texturePtr, sf::Font& aFont);

		void setItemAmount(unsigned int newItemAmount);

		unsigned int& getItemAmount();
	
		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);
	};

}
#endif