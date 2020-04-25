#include "pathNode.h"




MP::PathNode::PathNode()
{
	_next_node = nullptr;
	_parent = nullptr;
}

void MP::PathNode::calculateHValue(sf::Vector2f meta)
{
	_cost_H = abs(meta.x - this->_a_map_element->getLandTile().getObiectCoord().x);
	_cost_H += abs(meta.y - this->_a_map_element->getLandTile().getObiectCoord().y);
}

void MP::PathNode::calculateGValue(sf::Vector2f start)
{
	_cost_G = abs(start.x - this->_a_map_element->getLandTile().getObiectCoord().x);
	_cost_G += abs(start.y - this->_a_map_element->getLandTile().getObiectCoord().y);
}

void MP::PathNode::setParentForElement(MP::PathNode* up, MP::PathNode* down, MP::PathNode* left, MP::PathNode* right)
{

	if (up != nullptr)
	{
		if (up->_parent == nullptr)
			up->_parent = this;
	}
	if (down != nullptr)
	{
		if (down->_parent == nullptr)
			down->_parent = this;
	}
	if (left != nullptr)
	{
		if (left->_parent == nullptr)
			left->_parent = this;
	}
	if (right != nullptr)
	{
		if (right->_parent == nullptr)
			right->_parent = this;
	}
}

MP::MapElement*& MP::PathNode::getMapElementAddress()
{
	return _a_map_element;
}

MP::PathNode*& MP::PathNode::getNextNode()
{
	return _next_node;
}

void MP::PathNode::setParent(MP::PathNode* aNode)
{
	_parent = aNode;
}

MP::PathNode*& MP::PathNode::getParent()
{
	return _parent;
}

MP::PathNode& MP::PathNode::operator=(MP::MapElement*& anElement)
{
	this->_a_map_element = anElement;
	return *this;
}

int MP::PathNode::getCostF()
{
	return _cost_F;
}

void MP::PathNode::calculate(sf::Vector2f start, sf::Vector2f stop)
{
	calculateHValue(stop);
	calculateGValue(start);
	_cost_F = _cost_H;
	_cost_F += _cost_G;
}