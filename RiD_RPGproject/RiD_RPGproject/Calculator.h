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

		
		sf::Vector2f checkingVector;//Variable used in player auto move procedure;

		void _start_procedure_player_move( MP::Player& aPlayer, sf::Clock& aGameClock, TaskManager& aMainTaskManager);

		void _start_procedure_player_animation( MP::Player& aPlayer, sf::Clock& aGameClock, TaskManager& aMainTaskManager);

		void _start_procedure_camera_zoom(ObiectManager& aObiectManager, TaskManager& aTaskManager, Camera& aCamera);

		void _start_procedure_correct_camera(sf::Vector2f newCoord, Camera& aCamera);

		void _start_procedure_player_auto_or_normal_move(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock);

		void _start_procedure_menu(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, Camera& aCamera);
		
		void _start_procedure_map_gui(ObiectManager& aObiectManager);

		void _start_procedure_player(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock);

		void _start_procedure_trees(sf::Clock& globalClock, ObiectManager& aObiectManager);

		void _start_procedure_computer_players(ObiectManager& aObiectManager, sf::Clock& aGameClock,Map& aMap);

		void _start_procedure_camera(ObiectManager& aObiectManager, TaskManager& aMainTaskManager, sf::Vector2f newCoord, Camera& aCamera);

		void _start_procedure_cursor(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, Camera& aCamera);
		
		void _start_procedure_marketplace(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, Camera& aCamera);
	
	public:

		void startMainGameProcedures(TaskManager& aTaskManager, ObiectManager& aObiectManager, sf::Clock& globalClock, Camera& aCamera);

		void StartMenuProcedures(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, Camera& aCamera);
	
	};
}
#endif