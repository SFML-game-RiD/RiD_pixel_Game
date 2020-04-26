#ifndef TREE_H
#define TREE_H

#include "Obiect.h"

namespace MP
{
	class Tree :public Obiect
	{
	private:

		void _tree_animation(sf::Clock& globalClock);

	public:

		Tree(sf::Texture* texturePtr, sf::Vector2f coord, float treeScale);

		void update(sf::Clock& globalClock);

		void render(sf::RenderWindow &mainWindow);

	};
}
#endif // !_TREE_H_

