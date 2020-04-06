#include "pathCreator.h"


MP::PathCreator::PathCreator(Map& aMap)
{
	_map_copy = &aMap;
	_path_map_element_for_export = nullptr;
	_path = nullptr;
	_closed_list = nullptr;
	_open_list = nullptr;
}

MP::MapElement*& MP::PathCreator::findPath(sf::Vector2f start, sf::Vector2f stop)
{

	_path_map_element_for_export = nullptr;
	_path = nullptr;
	_closed_list = nullptr;
	_open_list = nullptr;

	//Saving coordinates.
	this->_start = start;
	this->_stop = stop;

	//Adding to open list start coord.
	_add(start);

	//Finding smallest F value.
	*this - _find_smallest_F();

	//Setting parent pointer to his own addres. It helps while creating path.
	_closed_list->setParent(_closed_list);

	while (_path == nullptr)
	{

		_find_walkable_elements();

		_set_parent_for_elements();

		*this - _find_smallest_F();

		_try_to_create_path();
	}

	_create_path_for_export();

	_delete_list(_open_list);
	_delete_list(_closed_list);


	return _path_map_element_for_export;
}

MP::PathCreator& MP::PathCreator::operator=(MP::Map& aMap)
{
	_map_copy->copyMapElementList(aMap.getMapElementList());

	return *this;
}

MP::PathCreator& MP::PathCreator::operator^(MP::PathNode*& aNode)
{
	RiD::AssetManager tempAsset;
	int uslessInt;
	MapElement* tmpElementPtr = new MapElement(tempAsset, aNode->getMapElementAddress()->getLandTile().getObiectCoord().x, aNode->getMapElementAddress()->getLandTile().getObiectCoord().y, '~');

	if (_path_map_element_for_export == nullptr)
	{

		this->_path_map_element_for_export = tmpElementPtr;

		return*this;
	}
	else
	{
		MapElement* tmp = _path_map_element_for_export;
		while (tmp->getNextElement() != nullptr)
		{
			tmp = tmp->getNextElement();
		}
		tmp->setNextPtr(tmpElementPtr);
		return*this;
	}
	return *this;
}

MP::PathCreator& MP::PathCreator::operator+(PathNode*& aNode)
{
	if (_open_list == nullptr)
	{
		_open_list = aNode;

		return *this;
	}
	else
	{
		PathNode* tmp = _open_list;

		while (tmp->getNextNode() != nullptr)
			tmp = tmp->getNextNode();

		tmp->getNextNode() = aNode;

		return *this;
	}
}

MP::PathCreator& MP::PathCreator::operator-(MP::PathNode* aNode)
{

	PathNode* tmp = _closed_list;


	if (tmp == nullptr)
	{
		_closed_list = aNode;
		this->_disconnect_from_open_list(aNode->getMapElementAddress());

		return *this;
	}
	else
	{

		while (tmp->getNextNode() != nullptr) tmp = tmp->getNextNode();

		tmp->getNextNode() = aNode;

		this->_disconnect_from_open_list(aNode->getMapElementAddress());

		return *this;
	}


}

MP::PathNode* MP::PathCreator::_find_path_node(MapElement* whichNodeContain)
{
	PathNode* tmp = _open_list;

	while (tmp != nullptr)
	{
		if (tmp->getMapElementAddress() == whichNodeContain) return tmp;

		tmp = tmp->getNextNode();
	}

	tmp = _closed_list;

	while (tmp != nullptr)
	{
		if (tmp->getMapElementAddress() == whichNodeContain) return tmp;

		tmp = tmp->getNextNode();
	}

	return nullptr;
}

MP::PathNode*& MP::PathCreator::_find_smallest_F()
{
	PathNode* smallestFElement;
	PathNode* tmp = _open_list;

	smallestFElement = tmp;

	if (tmp->getNextNode() != nullptr)
		tmp = tmp->getNextNode();

	while (tmp != nullptr)
	{
		if (smallestFElement->getCostF() > tmp->getCostF())
		{
			smallestFElement = tmp;
		}
		tmp = tmp->getNextNode();
	}
	return smallestFElement;
}

MP::PathNode* MP::PathCreator::_find_in_closed_list(MapElement* whichNodeContain)
{
	PathNode* tmp = _closed_list;

	while (tmp != nullptr)
	{
		if (tmp->getMapElementAddress() == whichNodeContain) return tmp;

		tmp = tmp->getNextNode();
	}
	return nullptr;

}

MP::PathNode* MP::PathCreator::_find_in_open_list(MapElement* whichNodeContain)
{
	PathNode* tmp = _open_list;

	while (tmp != nullptr)
	{
		if (tmp->getMapElementAddress() == whichNodeContain) return tmp;

		tmp = tmp->getNextNode();
	}

	return nullptr;
}

void MP::PathCreator::_closed_list_delete_node(MapElement* addresFromNode)
{
	PathNode* tmp = _closed_list;
	PathNode* ghost = _closed_list;


	if (tmp->getMapElementAddress() == addresFromNode)//If it is first node.
	{
		_closed_list = _closed_list->getNextNode();
		delete tmp;
		return;
	}
	else
	{
		tmp = tmp->getNextNode();
	}

	//Starting looking deep.

	while (tmp != nullptr)
	{
		if (tmp->getMapElementAddress() == addresFromNode)
		{
			ghost->getNextNode() = tmp->getNextNode();
			delete tmp;
			return;
		}
		tmp = tmp->getNextNode();
		ghost = ghost->getNextNode();
	}
	return;
}

void MP::PathCreator::_disconnect_from_open_list(MapElement* whichNodeContain)
{
	PathNode* tmp = _open_list;
	PathNode* ghost = _open_list;


	if (tmp->getMapElementAddress() == whichNodeContain)
	{
		_open_list = _open_list->getNextNode();
		tmp->getNextNode() = nullptr;
		return;
	}
	else
	{
		tmp = tmp->getNextNode();
	}



	while (tmp != nullptr)
	{
		if (tmp->getMapElementAddress() == whichNodeContain)
		{
			ghost->getNextNode() = tmp->getNextNode();
			tmp->getNextNode() = nullptr;
			return;
		}
		tmp = tmp->getNextNode();
		ghost = ghost->getNextNode();
	}
	return;
}

void MP::PathCreator::_set_parent_for_elements()
{
	PathNode* tmp;
	tmp = _closed_list;

	while (tmp != nullptr)
	{
		//Setting parent for elements from open and closed list.
		tmp->setParentForElement(this->_find_path_node(tmp->getMapElementAddress()->getUpPtr()),
			this->_find_path_node(tmp->getMapElementAddress()->getDownPtr()),
			this->_find_path_node(tmp->getMapElementAddress()->getLeftPtr()), this->_find_path_node(tmp->getMapElementAddress()->getRightPtr()));
		tmp = tmp->getNextNode();
	}
}

void MP::PathCreator::_find_walkable_elements()
{
	PathNode* tmp = _closed_list;

	while (tmp != nullptr)
	{
		//Up.
		if (tmp->getMapElementAddress()->getUpPtr() != nullptr and tmp->getMapElementAddress()->getUpPtr()->isWalkable() == true) { //If element exist and is walkable. 

			if (this->_find_in_closed_list(tmp->getMapElementAddress()->getUpPtr()) == nullptr and
				this->_find_in_open_list(tmp->getMapElementAddress()->getUpPtr()) == nullptr)//If element is not in open or close list.
			{
				this->_add(tmp->getMapElementAddress()->getUpPtr()->getLandTile().getObiectCoord());
			}
		}

		//Down.
		if (tmp->getMapElementAddress()->getDownPtr() != nullptr and tmp->getMapElementAddress()->getDownPtr()->isWalkable() == true) {

			if (this->_find_in_closed_list(tmp->getMapElementAddress()->getDownPtr()) == nullptr and
				this->_find_in_open_list(tmp->getMapElementAddress()->getDownPtr()) == nullptr)
			{
				this->_add(tmp->getMapElementAddress()->getDownPtr()->getLandTile().getObiectCoord());
			}
		}

		//Left.
		if (tmp->getMapElementAddress()->getLeftPtr() != nullptr and tmp->getMapElementAddress()->getLeftPtr()->isWalkable() == true)
		{

			if (this->_find_in_closed_list(tmp->getMapElementAddress()->getLeftPtr()) == nullptr and
				this->_find_in_open_list(tmp->getMapElementAddress()->getLeftPtr()) == nullptr)
			{
				this->_add(tmp->getMapElementAddress()->getLeftPtr()->getLandTile().getObiectCoord());
			}
		}

		//Right.
		if (tmp->getMapElementAddress()->getRightPtr() != nullptr and tmp->getMapElementAddress()->getRightPtr()->isWalkable() == true)
		{

			if (this->_find_in_closed_list(tmp->getMapElementAddress()->getRightPtr()) == nullptr and
				this->_find_in_open_list(tmp->getMapElementAddress()->getRightPtr()) == nullptr)
			{
				this->_add(tmp->getMapElementAddress()->getRightPtr()->getLandTile().getObiectCoord());
			}
		}
		tmp = tmp->getNextNode();
	}
}

void MP::PathCreator::_add(sf::Vector2f aCoord)
{
	PathNode* tmp = new PathNode;
	MapElement* tmpElement = _map_copy->findElementAddress(aCoord, _map_copy->getMapElementList());


	*tmp = tmpElement;
	tmp->calculate(_start, _stop);

	*this + tmp;//Adding to open list.
}


void MP::PathCreator::_try_to_create_path()
{
	_path = this->_find_in_closed_list_by_coords(_stop);
}

MP::PathNode* MP::PathCreator::_find_in_closed_list_by_coords(sf::Vector2f stop)
{
	PathNode* tmp = _closed_list;

	while (tmp != nullptr)
	{
		if (tmp->getMapElementAddress()->getLandTile().getObiectCoord().x == stop.x and
			tmp->getMapElementAddress()->getLandTile().getObiectCoord().y == stop.y)
			return tmp;

		tmp = tmp->getNextNode();
	}
	return nullptr;
}

void MP::PathCreator::_create_path_for_export()
{
	_go_through_parents_and_create_export_list(_find_in_closed_list_by_coords(_stop));
}

void MP::PathCreator::_go_through_parents_and_create_export_list(PathNode* aPathNodeHead)
{

	if (aPathNodeHead->getParent() != aPathNodeHead)
	{
		_go_through_parents_and_create_export_list(aPathNodeHead->getParent());

		*this^ aPathNodeHead;
	}
	return;
}

void MP::PathCreator::_add_map_element_to_export_list(MapElement*& additiveElement)
{

	if (_path_map_element_for_export == nullptr)
	{
		_path_map_element_for_export = additiveElement;
		return;
	}

	MapElement* tmp = _path_map_element_for_export;
	while (tmp->getNextElement() != nullptr)
	{
		tmp = tmp->getNextElement();
	}
	tmp->setNextPtr(additiveElement);
	return;
}

void MP::PathCreator::_delete_list(PathNode* listHead)
{
	if (listHead == nullptr)
		return;
	else
	{
		_delete_list(listHead->getNextNode());
		delete listHead;
	}
}
