#ifndef _PATHNODE_H_
#define _PATHNODE_H_

#include "MapElement.h"
#include <Windows.h>

namespace MP
{
	class PathNode
	{
	private:

		/************************************************* PRIVATE ATTRIBUTES *************************************************/

		MP::MapElement* aMapElement;//Stores map element address.

		PathNode* nextNode;//Stores next element address.

		PathNode* parent;//Stores parent address.

		float costF;//Additioned costG + costH.

		float costG;//Startpoint distance.

		float costH;//Destination distance.

	public:

		/************************************************* PUBLIC METHODS *************************************************/

		//Sets ptrs to nullptr.
		PathNode();

		//Sets map's element.
		PathNode& operator=(MP::MapElement*& anElement);

		//Returns F value.
		int getCostF();

		//Calculates F G H value for element using coordinates below.
		void calculate(sf::Vector2f start, sf::Vector2f stop);

		//Calculates H value using coordinates in arguments.
		void calculateHValue(sf::Vector2f meta);

		//Calculates G value using coordinates in arguments.
		void calculateGValue(sf::Vector2f start);

		//Sets parents for each node in function arguments.
		void setParentForElement(PathNode* up, PathNode* down, PathNode* left, PathNode* right);

		//Returns map element's address.
		MP::MapElement*& getMapElementAddress();

		//Returns next node's address.
		PathNode*& getNextNode();

		//Sets parent for element using argument below.
		void setParent(PathNode* aNode);

		//Returns parent address.
		PathNode*& getParent();

	};
}
#endif