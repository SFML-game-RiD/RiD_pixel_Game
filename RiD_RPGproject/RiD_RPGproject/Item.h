#ifndef ITEM_H
#define ITEM_H
#include "Obiect.h"

namespace MP

{
	class Item:public Obiect
	{
	protected:

		int _item_amount;

		int _item_cost;

		sf::Text _item_amount_text;

	public:

		Item();

		Item(sf::Texture* texturePtr, sf::Font& aFont);

		 void setItemAmount(unsigned int newItemAmount);

		 int getItemAmount();

		virtual void setItemPosition(sf::Vector2f itemPosition);

		virtual void drawItem(sf::RenderWindow& mainWindow);

		void setTextPostion(sf::Vector2f newPosition); //retlative to obj coordination

		int getItemCost();

	};
}
#endif // !_ITEM_H_
