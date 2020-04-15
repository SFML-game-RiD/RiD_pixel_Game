#ifndef WOOD_H
#define WOOD_H
#include "Item.h"

namespace MP
{

	class Wood:public Item
	{
	private:

	public:

		Wood();

		Wood(sf::Texture* texturePtr, sf::Font& aFont);

		void setItemAmount(unsigned int newItemAmount);
		
		unsigned int& getItemAmount();

		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);
	};
}
#endif // !_WOOD_H_
