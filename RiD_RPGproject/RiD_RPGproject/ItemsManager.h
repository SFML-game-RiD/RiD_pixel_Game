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

	public:

		void setItems(sf::Font& aFont,unsigned int gold, sf::Texture* goldTextures, unsigned int iron, sf::Texture* ironTextures,
			unsigned int wood, sf::Texture* woodTextures, unsigned food, sf::Texture* foodTextures, unsigned int spearman,
			sf::Texture* spearmanTextures, unsigned int archer, sf::Texture* archerTextures, unsigned int swordsman, sf::Texture* swordsmanTextures );

		std::shared_ptr <Item>& getGold();
		std::shared_ptr <Item>& getIron();
		std::shared_ptr <Item>& getWood();
		std::shared_ptr <Item>& getFood();
		std::shared_ptr <Item>& getSpearman();
		std::shared_ptr <Item>& getArcher();
		std::shared_ptr <Item>& getSwordsman();
	};
}
#endif // !1
