#include "MapMove.h"

//void MP::MapMove::startProcedurePlayerMove(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock)
//{
//	switch (aTaskManager.getTask())
//	{
//	case(MP::TaskManager::taskType::taskGoUp):
//		//	moveBlockUp(*(aObiectManager.getPlayer()), aGameClock);
//		break;
//	case(MP::TaskManager::taskType::taskGoLeft):
//		//moveBlockLeft(*(aObiectManager.getPlayer()), aGameClock);
//		break;
//	case(MP::TaskManager::taskType::taskGoDown):
//		//moveBlockDown(*(aObiectManager.getPlayer()), aGameClock);
//		break;
//	case(MP::TaskManager::taskType::taskGoRight):
//		//moveBlockRight(*(aObiectManager.getPlayer()), aGameClock);
//		break;
//
//	}
//}


void MP::MapMove::moveBlockDown(ActiveObiect& obiect, sf::Clock currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getLastActiveTime() && obiect.getIsMoving())
	{
		movePixelDown(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
		obiect.setIsMoving(true);
	}
	else if (obiect.getBlockLenghtCopy() <= 0)
	{

		obiect.setIsMoving(false);
		obiect.resetBlockLenghtCopy();
	}
}

void MP::MapMove::moveBlockUp(ActiveObiect& obiect, sf::Clock currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getLastActiveTime()&& obiect.getIsMoving())
	{
		movePixelUp(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
		obiect.setIsMoving(true);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{

		obiect.setIsMoving(false);
		obiect.resetBlockLenghtCopy();
	}
}

void MP::MapMove::moveBlockRight(ActiveObiect& obiect, sf::Clock currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getLastActiveTime() && obiect.getIsMoving())
	{
		movePixelRight(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
		obiect.setIsMoving(true);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.setIsMoving(false);
		obiect.resetBlockLenghtCopy();
	}
}

void MP::MapMove::moveBlockLeft(ActiveObiect& obiect, sf::Clock currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getLastActiveTime() && obiect.getIsMoving())
	{
		movePixelLeft(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
		obiect.setIsMoving(true);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.setIsMoving(false);
		obiect.resetBlockLenghtCopy();

	}
}

void MP::MapMove::movePixelDown(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first, obiect.getObiectCoord().second + 1);
}

void MP::MapMove::movePixelUp(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first, obiect.getObiectCoord().second - 1);
}

void MP::MapMove::movePixelRight(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first+1, obiect.getObiectCoord().second);
}

void MP::MapMove::movePixelLeft(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first-1, obiect.getObiectCoord().second);
}
