#include "TaskNode.h"


MP::TaskNode::TaskNode(taskType newTask)
{
	task = newTask;
}

MP::TaskNode::taskType MP::TaskNode::getTask()
{
	return task;
}
