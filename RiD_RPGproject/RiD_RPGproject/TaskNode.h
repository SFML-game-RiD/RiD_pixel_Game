#pragma once
#include <vector>
namespace MP
{
	class TaskNode
	{
	public:

		enum class taskType
		{

			taskNone,

			//Move basic tasks
			taskNormalMove,
			taskGoUp,
			taskGoDown,
			taskGoRight,
			taskGoLeft,

			//Auto move tasks
			taskAutoMove,
			taskBreakAutoMove,
			taskExecuteAutoMove,
			taskCreateAutoPath,

			//Camera tasks
			taskZoomIn,
			taskZoomOut,

			//Mouse tasks
			taskClickLeft,
			taskClickRight,
			taskDoubleClickLeft,
			taskWaitForDoubleClickLeft




		};

		taskType task;

	public:

		TaskNode(taskType newTask);

		TaskNode::taskType getTask();
	};
}