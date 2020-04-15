#ifndef SPEARMAN_H
#define SPEARMAN_H
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