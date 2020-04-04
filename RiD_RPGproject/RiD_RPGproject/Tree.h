#ifndef _TREE_H_
#define _TREE_H_

#include "StaticObiect.h"

namespace MP
{
	class Tree :public StaticObiect
	{
	private:


	public:

		Tree(sf::Texture* texturePtr, sf::Vector2f coord, float treeScale);

		void treeAnimation(sf::Clock& globalClock);

	};
}
#endif // !_TREE_H_

