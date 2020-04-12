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

		
		sf::Vector2f checkingVector;//Variable used in player auto move procedure;

		void _start_procedure_player_move( MP::Player& aPlayer, sf::Clock& aGameClock, TaskManager& aMainTaskManager);

		void _start_procedure_player_animation( MP::Player& aPlayer, sf::Clock& aGameClock, TaskManager& aMainTaskManager);

		void _start_procedure_camera_zoom(ObiectManager& aObiectManager, TaskManager& aTaskManager, Camera& aCamera);

		void _start_procedure_correct_camera(sf::Vector2f newCoord, Camera& aCamera);

		void _start_procedure_player_auto_or_normal_move(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock);

	public:

		void startProcedurePlayer(TaskManager& aTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock);

		void startProcedureTrees(sf::Clock& globalClock, ObiectManager& aObiectManager);

		void startProcedureComputerPlayers(ObiectManager& aObiectManager, sf::Clock& aGameClock,Map& aMap);

		void startProcedureCamera(ObiectManager& aObiectManager, TaskManager& aTaskManager, sf::Vector2f newCoord, Camera& aCamera);

		void startProcedureCursor(TaskManager& aTaskManager, ObiectManager& aObiectManager, Camera& aCamera);
	};
}
#endif