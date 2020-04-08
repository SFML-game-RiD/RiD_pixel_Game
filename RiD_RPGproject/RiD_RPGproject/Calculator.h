#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

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

		sf::Vector2f checkingVector;

		void _start_procedure_player_move(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock);

		void _start_procedure_player_animation(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock);

		void _start_procedure_camera_zoom(TaskManager& aTaskManager, Camera& aCamera);

		void _start_procedure_correct_camera(TaskManager& aTaskManager, sf::Vector2f newCoord, Camera& aCamera);

	public:

		void startProcedurePlayer(TaskManager& aTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock);

		void startProcedureTrees(sf::Clock& globalClock, ObiectManager& aObiectManager);

		void startProcedureComputerPlayers(ObiectManager& aObiectManager, sf::Clock& aGameClock,Map& aMap);

		void startProcedureCamera(TaskManager& aTaskManager, sf::Vector2f newCoord, Camera& aCamera);

		void startProcedureCursor(TaskManager& aTaskManager, ObiectManager& aObiectManager, Camera& aCamera);
	};
}
#endif