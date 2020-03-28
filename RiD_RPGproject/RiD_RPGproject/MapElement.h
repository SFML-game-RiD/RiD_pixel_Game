#ifndef _MAPELEMENT_H_
#define _MAPELEMENT_H_

#include <memory>
#include "Land.h"
#include "Places.h"

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

		bool walkable;


		void _create_village(std::pair<int, int> coord);
		
		void _create_town(std::pair<int, int> coord);

		void _create_castle(std::pair<int, int> coord);

	public:

		Land & getLandTile();

		std::shared_ptr<Places>& getPlace();

		MapElement(int cordX,int cordY,char mark);


		MapElement *& getNextElement();

		MapElement*& getUpPtr();

		MapElement*& getDownPtr();

		MapElement*& getLeftPtr();

		MapElement*& getRightPtr();

		char getMark();

		void setUpPtr(MapElement* aMapElement);

		void setDownPtr(MapElement* aMapElement);

		void setLeftPtr(MapElement* aMapElement);

		void setRightPtr(MapElement* aMapElement);
	};
}
#endif