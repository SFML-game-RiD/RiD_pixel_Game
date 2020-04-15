#ifndef ARCHER_H
#define ARCHER_H
#include "Item.h"

namespace MP
{
	class Archer:public Item
	{
	private:

	public:
		Archer();

		Archer(sf::Texture* texturePtr, sf::Font& aFont);

	    void setItemAmount(unsigned int newItemAmount);

		unsigned int& getItemAmount();
	
		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);
	};

}
#endif