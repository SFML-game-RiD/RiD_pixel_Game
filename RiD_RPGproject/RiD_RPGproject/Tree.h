#ifndef TREE_H
#define TREE_H

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

