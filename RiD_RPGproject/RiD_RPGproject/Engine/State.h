#pragma once

namespace RiD
{
	class State
	{
	public:
		State() {}
		~State() {}

		//Initializes states
		virtual void initState() = 0; // or constructor
		//Updates
		virtual void updateState() = 0;
		//Draws user interface
		virtual void drawUI(float deltaTime) = 0;
		//Deletes state
		virtual void deleteState() = 0; // or destructor
	};
}

