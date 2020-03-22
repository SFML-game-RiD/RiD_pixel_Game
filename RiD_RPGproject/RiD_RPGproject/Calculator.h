#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "MapMove.h"
#include "TaskManager.h"
#include "Player.h"


namespace MP
{
	class Calculator
	{
	public:

		void startProcedurePlayerMove(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock);
	};
}
#endif