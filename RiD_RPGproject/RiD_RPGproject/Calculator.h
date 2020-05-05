#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Move.h"
#include "TaskManager.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Camera.h"

namespace MP
{
	class Calculator
	{
	private:

		void _computer_players_procedure(ObjectManager& aObiectManager, sf::Clock& gameClock,Map& aMap);

		void _trees_procedure(sf::Clock& globalClock, ObjectManager& aObiectManager);

	public:

		void startMainGameProcedures(TaskManager& aTaskManager, ObjectManager& aObiectManager, sf::Clock& globalClock, Camera& aCamera);

		void startMenuProcedures(TaskManager& aMainTaskManager, ObjectManager& aObiectManager, Camera& aCamera);
	
	};
}
#endif