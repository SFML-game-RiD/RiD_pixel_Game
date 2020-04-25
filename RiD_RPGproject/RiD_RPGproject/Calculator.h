#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Move.h"
#include "TaskManager.h"
#include "Player.h"
#include "ObiectManager.h"
#include "Camera.h"

namespace MP
{
	class Calculator
	{
	private:

		void _computer_players_procedure(ObiectManager& aObiectManager, sf::Clock& gameClock,Map& aMap);

		void _trees_procedure(sf::Clock& globalClock, ObiectManager& aObiectManager);

	public:

		void startMainGameProcedures(TaskManager& aTaskManager, ObiectManager& aObiectManager, sf::Clock& globalClock, Camera& aCamera);

		void StartMenuProcedures(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, Camera& aCamera);
	
	};
}
#endif