#include "Move.h"
#include <iostream>


void MP::Move::moveBlockDown(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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
		aTaskManager.endTask();
	}
}

void MP::Move::moveBlockUp(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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
		aTaskManager.endTask();
	}
}

void MP::Move::moveBlockRight(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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
		aTaskManager.endTask();
	}
}

void MP::Move::moveBlockLeft(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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
		aTaskManager.endTask();
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