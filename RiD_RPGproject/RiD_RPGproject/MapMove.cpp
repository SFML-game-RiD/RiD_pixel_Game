#include "MapMove.h"
#include <iostream>


void MP::MapMove::moveBlockDown(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
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
		aTaskManager.endTask();
	}
}

void MP::MapMove::moveBlockUp(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
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
		aTaskManager.endTask();
	}
}

void MP::MapMove::moveBlockRight(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() > obiect.getReadyTime())
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
		aTaskManager.endTask();
	}
}

void MP::MapMove::moveBlockLeft(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
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
		aTaskManager.endTask();
	}
}

void MP::MapMove::movePixelDown(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first, obiect.getObiectCoord().second + 4);
}

void MP::MapMove::movePixelUp(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first, obiect.getObiectCoord().second - 4);
}

void MP::MapMove::movePixelRight(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first+4, obiect.getObiectCoord().second);
}

void MP::MapMove::movePixelLeft(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first-4, obiect.getObiectCoord().second);
}
