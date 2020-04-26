#ifndef ITEMSMANAGER_H
#define ITEMSMANAGER_H
#include "Item.h"

namespace MP
{
	class ItemsManager
	{
	private:

		std::shared_ptr <Item> _gold;
		std::shared_ptr <Item> _iron;
		std::shared_ptr <Item> _wood;
		std::shared_ptr <Item> _food;
		std::shared_ptr <Item> _spearman;
		std::shared_ptr <Item> _archer;
		std::shared_ptr <Item> _swordsman;

	/*	std::unique_ptr <Item> _gold;
		std::unique_ptr <Item> _iron;
		std::unique_ptr <Item> _wood;
		std::unique_ptr <Item> _food;
		std::unique_ptr <Item> _spearman;
		std::unique_ptr <Item> _archer;
		std::unique_ptr <Item> _swordsman;*/

	public:

		void setItems(sf::Font& aFont,
			unsigned int gold, sf::Texture* goldTextures, 
			unsigned int iron, sf::Texture* ironTextures,
			unsigned int wood, sf::Texture* woodTextures, 
			unsigned int food, sf::Texture* foodTextures, 
			unsigned int spearman, sf::Texture* spearmanTextures,
			unsigned int archer, sf::Texture* archerTextures, 
			unsigned int swordsman, sf::Texture* swordsmanTextures );

		std::shared_ptr <Item>& getGold();
		std::shared_ptr <Item>& getIron();
		std::shared_ptr <Item>& getWood();
		std::shared_ptr <Item>& getFood();
		std::shared_ptr <Item>& getSpearman();
		std::shared_ptr <Item>& getArcher();
		std::shared_ptr <Item>& getSwordsman();

		//std::unique_ptr <Item>& getGold();
		//std::unique_ptr <Item>& getIron();
		//std::unique_ptr <Item>& getWood();
		//std::unique_ptr <Item>& getFood();
		//std::unique_ptr <Item>& getSpearman();
		//std::unique_ptr <Item>& getArcher();
		//std::unique_ptr <Item>& getSwordsman();

		bool addItem(std::shared_ptr <Item>& aItem, int ammount);

		bool subtractItem(std::shared_ptr <Item>& aItem, int ammount, int buyerGold);
	};
}
#endif // !1
