#ifndef _SWORDSMAN_H_
#define _SWORDSMAN_H_
#include "Item.h"

namespace MP
{
	class Swordsman :public Item
	{
	private:

	public:

		Swordsman();
		Swordsman(sf::Texture* texturePtr,sf::Font& aFont);

		void setItemAmount(unsigned int newItemAmount);

		unsigned int& getItemAmount();
	
		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);
	};
}
#endif 