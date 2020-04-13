#pragma once

#include "SFML/Graphics.hpp"

namespace AI
{
	class PathNode
	{
	private:
		int _F, _G, _H;
		PathNode* _next_node, *_parent_node;
		sf::Vector2i _position;
		bool _walkable;

		void _calcG(sf::Vector2i start);
		void _calcH(sf::Vector2i end);
	public:
		PathNode();

		sf::Vector2i getPosition();
		int getFCost();
		PathNode*& getParent();
		PathNode*& getPNext();
		void setPNext(PathNode *node);
		void setParent(PathNode *node);
		void setNotWalkable();
		void setFCost(sf::Vector2i end);
		void setPosition(sf::Vector2i pos);

		bool isWalkable();

		int getGCost(sf::Vector2i start);
	};
}