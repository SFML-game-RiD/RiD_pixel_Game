#ifndef GOLD_H
#define GOLD_H
#include "Item.h"

namespace MP
{
	class Gold :public Item
	{
	private:

	public:
		Gold();
		Gold(sf::Texture* texturePtr, sf::Font& aFont);

		void setItemAmount(unsigned int newItemAmount);

		unsigned int& getItemAmount();

		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);
	};
}
#endif