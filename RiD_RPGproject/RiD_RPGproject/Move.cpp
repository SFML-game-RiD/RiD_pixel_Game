#include "Move.h"
#include <iostream>


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
		obiect.aPawnObiectTaskManager.endTask(MP::TaskManager::taskRange::order);
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
		obiect.aPawnObiectTaskManager.endTask(MP::TaskManager::taskRange::order);
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
		obiect.aPawnObiectTaskManager.endTask(MP::TaskManager::taskRange::order);
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
		obiect.aPawnObiectTaskManager.endTask(MP::TaskManager::taskRange::order);
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
		aMainTaskManager.endTask(MP::TaskManager::taskRange::order);
		aMainTaskManager.endTask(MP::TaskManager::taskRange::mainOrder);
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
		aMainTaskManager.endTask(MP::TaskManager::taskRange::order);
		aMainTaskManager.endTask(MP::TaskManager::taskRange::mainOrder);
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
		aMainTaskManager.endTask(MP::TaskManager::taskRange::order);
		aMainTaskManager.endTask(MP::TaskManager::taskRange::mainOrder);
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
		aMainTaskManager.endTask(MP::TaskManager::taskRange::order);
		aMainTaskManager.endTask(MP::TaskManager::taskRange::mainOrder);
	}
}

void MP::Move::movePixelDown(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x, obiect.getObiectCoord().y + obiect.getVelocity());
}

void MP::Move::movePixelUp(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x, obiect.getObiectCoord().y - obiect.getVelocity());
}

void MP::Move::movePixelRight(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x + obiect.getVelocity(), obiect.getObiectCoord().y);
}

void MP::Move::movePixelLeft(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x - obiect.getVelocity(), obiect.getObiectCoord().y);
}