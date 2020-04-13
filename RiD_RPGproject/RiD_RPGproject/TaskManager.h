#ifndef _TASKMANAGER_H_
#define _TASKMANAGER_H_


namespace MP
{
	class TaskManager
	{
	public:

		
		enum class stateType
	{
			stateGame,
			stateMainMenu,
			StatePlacesMenu
	};
	enum class taskType
		{
			//Move basic tasks

			taskNone,
			taskGoUp,
			taskGoDown,
			taskGoRight,
			taskGoLeft,
			
			//Auto move tasks
			taskAutoMove,
			taskNormalMove,
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

	enum class taskRange
	{
		mainOrder,
		order,
		reply
	
	};

	private:
		
		stateType _game_state;

		taskType _game_order;
	
		taskType _game_reply;

		taskType _game_main_order;
	
	public:

		TaskManager();

		taskType getTask(taskRange aTaskRange);

		void endTask(taskRange aTaskRange);

		void setTask(taskRange aTaskRange, taskType typeOfTask);

		void resetOrdersAndReply();

		void setState(stateType aNewStateType);

		stateType getCurrentState();
	};
}

#endif // !_TASKMANAGER_H_