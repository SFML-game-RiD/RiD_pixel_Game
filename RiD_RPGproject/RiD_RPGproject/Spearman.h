#ifndef _SPEARMAN_H_
#define _SPEARMAN_H_
#include "Item.h"

namespace MP
{
	class Spearman :public Item
	{
	private:

	public:
		Spearman();
		Spearman(sf::Texture* texturePtr, sf::Font& aFont);

		void setItemAmount(unsigned int newItemAmount);

		 unsigned int& getItemAmount();

		 void setItemPosition(sf::Vector2f itemPosition);

		 void drawItem(sf::RenderWindow& mainWindow);
	};
}
#endif