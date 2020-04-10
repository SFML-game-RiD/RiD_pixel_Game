#pragma once

#include "RTBPathGenerator.h"

namespace AI
{
	void RTBPathGenerator::_addToOpenedList(PathNode*& node)
	{
		if (_opened_list_head)
		{
			node->setPNext(_opened_list_head);
			_opened_list_head = node;
		}
		else
		{
			_opened_list_head = node;
			node->setPNext(nullptr);
		}
	}

	void RTBPathGenerator::_moveToClosedList(PathNode*& node)
	{
		PathNode* tmp = this->_cutOffNodeFromOpen(node);
		this->_addToOpenedList(tmp);;
	}

	void RTBPathGenerator::_deleteOpenedList()
	{
		PathNode* curr = _opened_list_head;
		PathNode* next;
		while (curr)
		{
			next = curr->getPNext();
			delete curr;
			curr = next;
		}
		delete _opened_list_head;
	}

	void RTBPathGenerator::_deleteClosedList()
	{
		PathNode* curr = _closed_list_head;
		PathNode* next;
		while (curr)
		{
			next = curr->getPNext();
			delete curr;
			curr = next;
		}
		delete _closed_list_head;
	}

	bool RTBPathGenerator::_ifExists(sf::Vector2i position, PathNode* pHead)
	{
		PathNode* tmp;
		if (pHead == nullptr)
			return false;
		else
		{
			tmp = pHead;
			while (tmp->getPosition() != position)
			{
				if (tmp->getPNext() == nullptr)
					return false;
				else
					tmp = tmp->getPNext();
			}
		}
		return true;
	}

	PathNode* RTBPathGenerator::_cutOffNodeFromOpen(PathNode*& node)
	{
		if (_opened_list_head == node)
		{
			PathNode* ptr = _opened_list_head;
			_opened_list_head = ptr->getPNext();
			ptr->setPNext(nullptr);
			return ptr;
		}
		else
		{
			PathNode* ptr = _opened_list_head;
			while (ptr->getPNext())
			{
				if (ptr->getPNext() == node)
				{
					node = ptr->getPNext();
					ptr->setPNext(node->getPNext());
					node->setPNext(nullptr);
					return node;
				}
				ptr = ptr->getPNext();
			}
		}
	}

	PathNode* RTBPathGenerator::_findSmallestF()
	{
		PathNode* smallestFElement;
		PathNode* tmp = _opened_list_head;

		smallestFElement = tmp;

		if (tmp->getPNext() != nullptr)
			tmp = tmp->getPNext();

		while (tmp != nullptr)
		{
			if (smallestFElement->getFCost(_start, _end) > tmp->getFCost(_start, _end))
			{
				smallestFElement = tmp;
			}
			tmp = tmp->getPNext();
		}
		return smallestFElement;
	}

	RTBPathGenerator::RTBPathGenerator() : _path(nullptr), _opened_list_head(nullptr), _closed_list_head(nullptr)
	{
	}

	void RTBPathGenerator::findPath(sf::Vector2i start, sf::Vector2i end)
	{
		_start = start;
		_end = end;

		PathNode* first = new PathNode(_start);
		this->_addToOpenedList(first);
		while (_opened_list_head)
		{
			PathNode* current = _findSmallestF();
			_moveToClosedList(current);

			if (current->getPosition() == _end)
				return;

			for (unsigned short i = ;;++j)
			{
				for (unsigned short j=;;++j)
				{
					if (_walkable_area[i][j] == 1 || _ifExists(sf::Vector2i(i, j), _closed_list_head))
						continue;
					else if(!_ifExists(sf::Vector2i(i,j), _opened_list_head) || )///to do
					{

					}
				}
			}
		}
		_deleteOpenedList();
		_deleteClosedList();
	}
}