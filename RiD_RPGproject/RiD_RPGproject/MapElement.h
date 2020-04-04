#ifndef _MAPELEMENT_H_
#define _MAPELEMENT_H_

#include <memory>
#include "Land.h"
#include "Places.h"
#include "Engine/AssetManager.h"

namespace MP
{
	class MapElement
	{
	private:
	
		MapElement* _up_element, * _down_element, * _left_element, * _right_element;

		MapElement* _next_element;

		std::shared_ptr<Land> _land_tile;

		std::shared_ptr<Places> _a_place;

		char _mark;

		bool _walkable;

	
		void _create_village(sf::Texture* texturePtr, sf::Vector2f coord);

		void _create_town(sf::Texture* texturePtr, sf::Vector2f coord);

		void _create_castle(sf::Texture* texturePtr, sf::Vector2f coord);

	public:

		Land & getLandTile();

		std::shared_ptr<Places>& getPlace();

		MapElement(RiD::AssetManager &aAssetManager,int cordX,int cordY,char mark);




		MapElement *& getNextElement();

		MapElement*& getUpPtr();

		MapElement*& getDownPtr();

		MapElement*& getLeftPtr();

		MapElement*& getRightPtr();

		char getMark();

		void setNextPtr(MapElement* aMapElement);

		void setUpPtr(MapElement* aMapElement);

		void setDownPtr(MapElement* aMapElement);

		void setLeftPtr(MapElement* aMapElement);

		void setRightPtr(MapElement* aMapElement);

		bool isWalkable();

		MapElement* returnAddress();
	};
}
#endif