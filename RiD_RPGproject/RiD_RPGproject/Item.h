#ifndef ITEM_H
#define ITEM_H
#include "Obiect.h"

namespace MP

{
	class Item:public Obiect
	{
	protected:

		unsigned int _item_amount;

		unsigned int _item_cost;

		sf::Text _item_amount_text;

	public:

		Item();

		Item(sf::Texture* texturePtr, sf::Font& aFont);

		virtual void setItemAmount(unsigned int newItemAmount);

		virtual unsigned int& getItemAmount();

		virtual void setItemPosition(sf::Vector2f itemPosition);

		virtual void drawItem(sf::RenderWindow& mainWindow);
	};
}
#endif // !_ITEM_H_
