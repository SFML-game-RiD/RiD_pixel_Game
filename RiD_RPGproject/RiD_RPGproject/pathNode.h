#ifndef _PATHNODE_H_
#define _PATHNODE_H_

#include "MapElement.h"

namespace MP
{
	class PathNode
	{
	private:

		/************************************************* PRIVATE ATTRIBUTES *************************************************/

		MP::MapElement* _a_map_element;//Stores map element address.

		PathNode* _next_node;//Stores next element address.

		PathNode* _parent;//Stores parent address.

		float _cost_F;//Additioned costG + costH.

		float _cost_G;//Startpoint distance.

		float _cost_H;//Destination distance.

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

		PathNode* getNextNodeCopy();

		//Sets parent for element using argument below.
		void setParent(PathNode* aNode);

		//Returns parent address.
		PathNode*& getParent();

		void setNextNode(PathNode* aNextNode);

	};
}
#endif