#include "Move.h"


void MP::Move::moveBlockDown(PawnObiect& obiect, sf::Clock& currentTime)
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
		obiect.aPawnObiectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockUp(PawnObiect& obiect, sf::Clock& currentTime)
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
		obiect.aPawnObiectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockRight(PawnObiect& obiect, sf::Clock& currentTime)
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
		obiect.aPawnObiectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockLeft(PawnObiect& obiect, sf::Clock& currentTime)
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
		obiect.aPawnObiectTaskManager.deleteTaskList();
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

void MP::Move::movePixelDown(ActiveObiect& obiect)
{
	obiect.setObiectCoord(int(obiect.getObiectCoord().x), int(obiect.getObiectCoord().y + obiect.getVelocity()));
}

void MP::Move::movePixelUp(ActiveObiect& obiect)
{
	obiect.setObiectCoord(int(obiect.getObiectCoord().x), int(obiect.getObiectCoord().y - obiect.getVelocity()));
}

void MP::Move::movePixelRight(ActiveObiect& obiect)
{
	obiect.setObiectCoord(int(obiect.getObiectCoord().x + obiect.getVelocity()), int(obiect.getObiectCoord().y));
}

void MP::Move::movePixelLeft(ActiveObiect& obiect)
{
	obiect.setObiectCoord(int(obiect.getObiectCoord().x - obiect.getVelocity()), int(obiect.getObiectCoord().y));
}