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

		void _calcG(sf::Vector2i start);
		void _calcH(sf::Vector2i end);
	public:
		PathNode(sf::Vector2i position);

		sf::Vector2i getPosition();
		int getFCost(sf::Vector2i start, sf::Vector2i end);
		PathNode*& getParent();
		PathNode*& getPNext();
		void setPNext(PathNode *node);
		void setParent(PathNode *node);
	};
}