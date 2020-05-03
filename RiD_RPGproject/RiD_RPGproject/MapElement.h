#ifndef MAPELEMENT_H
#define MAPELEMENT_H

#include "Land.h"
#include "Places.h"
#include "Engine/AssetManager.h"

namespace MP
{
	class MapElement
	{
	private:

		MapElement* _next_element;

		std::shared_ptr<Land> _land_tile;

		std::shared_ptr<Places> _a_place;

		char _mark;

		bool _walkable;

		void _create_village(sf::Texture* texturePtr, sf::Vector2f coord);

		void _create_town(sf::Texture* texturePtr, sf::Vector2f coord);

		void _create_castle(sf::Texture* texturePtr, sf::Vector2f coord);

	public:

		MapElement(RiD::AssetManager &aAssetManager,int cordX,int cordY,char mark);

		Land & getLandTile();

		std::shared_ptr<Places>& getPlace();

		

		MapElement *& getNextElement();

		char getMark();

		void setNextPtr(MapElement* aMapElement);

		bool isWalkable();

		MapElement* returnAddress();
	};
}
#endif