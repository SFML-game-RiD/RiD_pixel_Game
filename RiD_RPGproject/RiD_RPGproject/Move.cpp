#include "Move.h"


void MP::Move::moveBlockDown(PawnObject& obiect, sf::Clock& currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		movePixelDown(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0)
	{
		obiect.resetBlockLenghtCopy();
		obiect.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockUp(PawnObject& obiect, sf::Clock& currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		movePixelUp(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		obiect.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockRight(PawnObject& obiect, sf::Clock& currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() > obiect.getReadyTime())
	{
		movePixelRight(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		obiect.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockLeft(PawnObject& obiect, sf::Clock& currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		movePixelLeft(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		obiect.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockDown(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		movePixelDown(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0)
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.deleteTaskList();

	}
}

void MP::Move::moveBlockUp(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		movePixelUp(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockRight(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() > obiect.getReadyTime())
	{
		movePixelRight(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockLeft(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		movePixelLeft(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.deleteTaskList();
	}
}

void MP::Move::movePixelDown(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x), int(obiect.getObjectCoord().y + obiect.getVelocity()));
}

void MP::Move::movePixelUp(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x), int(obiect.getObjectCoord().y - obiect.getVelocity()));
}

void MP::Move::movePixelRight(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x + obiect.getVelocity()), int(obiect.getObjectCoord().y));
}

void MP::Move::movePixelLeft(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x - obiect.getVelocity()), int(obiect.getObjectCoord().y));
}