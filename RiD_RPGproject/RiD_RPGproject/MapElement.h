#ifndef _MAPELEMENT_H_
#define _MAPELEMENT_H_

#include <memory>
#include "Land.h"

namespace MP
{
	class MapElement
	{
	private:
	
		MapElement* _up_element, * _down_element, * _left_element, * _right_element;

		MapElement* _next_element;

		std::shared_ptr<Land> _land_tile;


	public:


		Land & getLandTile();




		MapElement(int cordX,int cordY,char mark);

		MapElement *& getNextElement();

		MapElement*& getUpPtr();

		MapElement*& getDownPtr();

		MapElement*& getLeftPtr();

		MapElement*& getRightPtr();
	};
}
#endif