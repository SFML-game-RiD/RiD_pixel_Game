#ifndef _TREE_H_
#define _TREE_H_

#include "StaticObiect.h"

namespace MP
{
	class Tree :public StaticObiect
	{
	public:

		Tree(/*std::pair<int, int> coord*/sf::Vector2f coord);

		void treeAnimation(sf::Clock& globalClock);

	};
}
#endif // !_TREE_H_

