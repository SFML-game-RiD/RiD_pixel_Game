#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "PathNode.h"

namespace AI
{
	class RTBPathGenerator
	{
	private:
		std::vector<std::vector<PathNode>> _walkable_area;
		PathNode* _path;
		PathNode* _opened_list_head, * _closed_list_head;
		sf::Vector2i _start, _end;
		unsigned int _width, _height;

		void _addToOpenedList(PathNode*& node);
		void _addToPathList(PathNode*& node);
		void _moveToClosedList(PathNode*& node);
		void _moveToExportList(PathNode*& node);

		void _deleteOpenedList();
		void _deleteClosedList();
		void _NeighbourPosition(unsigned short i, unsigned short j, unsigned short points[]);
		void _generatePath();

		bool _ifExists(PathNode neighbour, PathNode* pHead);

		PathNode* _cutOffNodeFromOpen(PathNode*& node);
		PathNode* _cutOffNodeFromClosed(PathNode*& node);
		PathNode* _findSmallestF();
		PathNode* _findByPosition(sf::Vector2i position);
	public:
		RTBPathGenerator(std::vector<std::vector<PathNode>>& walkable_area);

		void findPath(sf::Vector2i start, sf::Vector2i end);
		PathNode*& getPath();
		PathNode* getMiddle();

		int distance(sf::Vector2i start, sf::Vector2i end);
	};
}