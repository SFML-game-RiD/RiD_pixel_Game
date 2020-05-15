#include "TaskNode.h"


MP::TaskNode::TaskNode(taskType newTask, bool block)
{
	_task = newTask;
}

MP::TaskNode::taskType MP::TaskNode::getTask()
{
	return _task;
}