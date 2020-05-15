#include "Move.h"



void MP::Move::moveBlockDown(PawnObject& obiect, sf::Clock& currentTime)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		_move_pixel_down(obiect);
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
		_move_pixel_up(obiect);
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
		_move_pixel_right(obiect);
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
		_move_pixel_left(obiect);
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
		_move_pixel_down(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0)
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_DOWN, true);

	}
}

void MP::Move::moveBlockUp(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		_move_pixel_up(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_UP, true);
	}
}

void MP::Move::moveBlockRight(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() > obiect.getReadyTime())
	{
		_move_pixel_right(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_RIGHT, true);
	}
}

void MP::Move::moveBlockLeft(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager)
{
	if (obiect.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= obiect.getReadyTime())
	{
		_move_pixel_left(obiect);
		obiect.decreaseBlockLengthCopy();
		obiect.setLastActive(currentTime);
	}
	else if (obiect.getBlockLenghtCopy() <= 0) // Arrived
	{
		obiect.resetBlockLenghtCopy();
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_LEFT, true);
	}
}

void MP::Move::_move_pixel_down(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x), int(obiect.getObjectCoord().y + obiect.getVelocity()));
}

void MP::Move::_move_pixel_up(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x), int(obiect.getObjectCoord().y - obiect.getVelocity()));
}

void MP::Move::_move_pixel_right(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x + obiect.getVelocity()), int(obiect.getObjectCoord().y));
}

void MP::Move::_move_pixel_left(ActiveObject& obiect)
{
	obiect.setObjectCoord(int(obiect.getObjectCoord().x - obiect.getVelocity()), int(obiect.getObjectCoord().y));
}

void MP::Move::tryToMoveUp(PawnObject &pawn ,Map& aMap, TaskManager& aMainTaskManager)
{
	if (pawn.checkGoUp(aMap) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_UP);
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}

void MP::Move::tryToMoveDown(PawnObject& pawn, Map& aMap, TaskManager& aMainTaskManager)
{
	if (pawn.checkGoDown(aMap) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_DOWN);
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}

void MP::Move::tryToMoveLeft(PawnObject& pawn, Map& aMap, TaskManager& aMainTaskManager)
{
	if (pawn.checkGoLeft(aMap) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_LEFT);
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}

void MP::Move::tryToMoveRight(PawnObject& pawn, Map& aMap, TaskManager& aMainTaskManager)
{
	if (pawn.checkGoRight(aMap) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT);
		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}