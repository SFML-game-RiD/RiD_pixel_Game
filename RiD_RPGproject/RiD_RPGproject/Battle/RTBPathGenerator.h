#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "PathNode.h"

namespace AI
{
	class RTBPathGenerator
	{
	private:
		std::vector<std::vector<bool>> _walkable_area;
		PathNode* _path;
		PathNode* _opened_list_head, * _closed_list_head;
		sf::Vector2i _start, _end;

		void _addToOpenedList(PathNode*& node);
		void _moveToClosedList(PathNode*& node);

		void _deleteOpenedList();
		void _deleteClosedList();

		bool _ifExists(sf::Vector2i position, PathNode* pHead);

		PathNode* _cutOffNodeFromOpen(PathNode*& node);
		PathNode* _findSmallestF();
	public:
		RTBPathGenerator();

		void findPath(sf::Vector2i start, sf::Vector2i end);
	};
}