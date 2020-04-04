#include "MapMove.h"
#include <iostream>


void MP::MapMove::moveBlockDown(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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

void MP::MapMove::moveBlockUp(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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

void MP::MapMove::moveBlockRight(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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

void MP::MapMove::moveBlockLeft(ActiveObiect& obiect, sf::Clock& currentTime, TaskManager& aTaskManager)
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

void MP::MapMove::movePixelDown(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x, obiect.getObiectCoord().y + obiect.getVelocity());
}

void MP::MapMove::movePixelUp(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x, obiect.getObiectCoord().y - obiect.getVelocity());
}

void MP::MapMove::movePixelRight(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x + obiect.getVelocity(), obiect.getObiectCoord().y);
}

void MP::MapMove::movePixelLeft(ActiveObiect& obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().x - obiect.getVelocity(), obiect.getObiectCoord().y);
}