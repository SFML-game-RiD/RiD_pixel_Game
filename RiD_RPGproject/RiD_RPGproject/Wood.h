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

		void setItemPosition(sf::Vector2f itemPosition);

		void drawItem(sf::RenderWindow& mainWindow);

		void update();

		void render();
	};
}
#endif // !_WOOD_H_
