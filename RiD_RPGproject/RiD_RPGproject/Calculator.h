#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <thread>
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

		std::thread th1, th2;


		void _computer_players_procedure(TaskManager& aMainTaskManager, SoundManager& aSoundManager, ObjectManager& aObiectManager, sf::Clock& gameClock,Map& aMap);

		void _trees_procedure(TaskManager& aMainTaskManager, sf::Clock& globalClock, ObjectManager& aObiectManager);

	public:

		void updateGame(SoundManager& aSoundManager, TaskManager& aTaskManager, ObjectManager& aObiectManager, sf::Clock& globalClock, Camera& aCamera);

	};
}
#endif