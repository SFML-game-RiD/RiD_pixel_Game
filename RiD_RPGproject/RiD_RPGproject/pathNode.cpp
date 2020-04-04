#include "pathNode.h"




MP::PathNode::PathNode()
{
	nextNode = nullptr;
	parent = nullptr;
}

void MP::PathNode::calculateHValue(sf::Vector2f meta)
{
	int x, y;

	x = meta.x - this->aMapElement->getLandTile().getObiectCoord().x;
	if (x < 0)
	{
		x = x * (-1);
	}
	y = meta.y - this->aMapElement->getLandTile().getObiectCoord().y;
	if (y < 0)
	{
		y = y * (-1);
	}

	costH = x;
	costH += y;
}

void MP::PathNode::calculateGValue(sf::Vector2f start)
{

	int x, y;

	x = start.x - this->aMapElement->getLandTile().getObiectCoord().x;
	if (x < 0)
	{
		x = x * (-1);
	}
	y = start.y - this->aMapElement->getLandTile().getObiectCoord().y;
	if (y < 0)
	{
		y = y * (-1);
	}

	costG = x;
	costG += y;
}

void MP::PathNode::setParentForElement(MP::PathNode*up, MP::PathNode*down, MP::PathNode*left, MP::PathNode*right)
{

	if (up != nullptr)
	{
		if (up->parent == nullptr) 
			up->parent = this;		
	}
	if (down != nullptr)
	{
		if (down->parent == nullptr)
			down->parent = this;
	}
	if (left != nullptr)
	{
		if (left->parent == nullptr)
			left->parent = this;
	}
	if (right != nullptr)
	{
		if (right->parent == nullptr)
			right->parent = this;	
	}
}

MP::MapElement *& MP::PathNode::getMapElementAddress()
{
	return aMapElement;
}

MP::PathNode*& MP::PathNode::getNextNode()
{
	return nextNode;
}

void MP::PathNode::setParent(MP::PathNode* aNode)
{
	parent = aNode;
}

MP::PathNode*& MP::PathNode::getParent()
{
	return parent;
}

MP::PathNode& MP::PathNode::operator=(MP::MapElement *& anElement)
{
	this->aMapElement = anElement;
	return *this;
}

int MP::PathNode::getCostF()
{
	return costF;
}

void MP::PathNode::calculate(sf::Vector2f start, sf::Vector2f stop)
{
	calculateHValue(stop);
	calculateGValue(start);
	costF = costH;
	costF += costG;
}
