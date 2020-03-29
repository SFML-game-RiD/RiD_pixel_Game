#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "MapMove.h"
#include "TaskManager.h"
#include "Player.h"
#include "ObiectManager.h"
#include "Camera.h"

namespace MP
{
	class Calculator
	{
	public:

		void startProcedurePlayerMove(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock);

		void startProcedurePlayerAnimation(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock);

		void startProcedureTreesAnimation(sf::Clock& globalClock, ObiectManager& aObiectManager);

		void startProcedureCameraZoom(TaskManager& aTaskManager, Camera &aCamera);

		void startProcedureCorrectCamera(TaskManager& aTaskManager, sf::Vector2f newCoord, Camera& aCamera);
	};
}
#endif