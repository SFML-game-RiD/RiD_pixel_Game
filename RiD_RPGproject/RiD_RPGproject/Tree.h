#pragma once
#include "Object.h"
#include "TaskManager.h"

namespace MP
{
	class Tree :public Object
	{
	private:

		//Changes object sprite relative to global clock.
		//@param globalClock measures game time.
		void _tree_animation(sf::Clock& globalClock);

	public:

		//Tree object constructor.
		//@param texturePtr object texture.
		//@param coord object coord.
		//@param treeScale changes size of tree.
		Tree(sf::Texture* texturePtr, sf::Vector2f coord, float treeScale);

		//Updates object.
		//@param globalClock measure game time.
		void update(TaskManager& aMainTaskManager, sf::Clock& globalClock);

		//Draws object on screen.
		//@param mainWindow game window.
		void render(TaskManager& aMainTaskManager, sf::RenderWindow &mainWindow);

	};
}