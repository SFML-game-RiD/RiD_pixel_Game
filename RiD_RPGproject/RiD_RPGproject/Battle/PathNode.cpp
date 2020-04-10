#pragma once

#include "PathNode.h"

namespace AI
{
	PathNode::PathNode(sf::Vector2i position)
	{
		_position = position;
	}

	sf::Vector2i PathNode::getPosition()
	{
		return _position;
	}

	int PathNode::getFCost(sf::Vector2i start, sf::Vector2i end)
	{
		_calcG(start);
		_calcH(end);
		_F = _G + _H;
		return _F;
	}

	PathNode*& PathNode::getParent()
	{
		return this->_parent_node;
	}

	PathNode*& PathNode::getPNext()
	{
		return this->_next_node;
	}

	void PathNode::setPNext(PathNode* node)
	{
		this->_next_node = node;
	}

	void PathNode::setParent(PathNode* node)
	{
		this->_parent_node = node;
	}

	void PathNode::_calcG(sf::Vector2i start)
	{
		_G = abs(start.x - _position.x);
		_G += abs(start.y - _position.y);
	}

	void PathNode::_calcH(sf::Vector2i end)
	{
		_H = abs(end.x - _position.x);
		_H += abs(end.y - _position.y);
	}
}