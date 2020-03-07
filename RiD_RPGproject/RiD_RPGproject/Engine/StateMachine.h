#pragma once
#include <memory>
#include <stack>

#include "State.h"

namespace RiD
{
	typedef std::unique_ptr<State> stateReference;

	class StateMachine
	{
	private:
		std::stack<stateReference> _stackOfStates;
		stateReference _newState;
		bool _isAdding = false, _isRemoving = false, _isReplacing = false;

	public:
		StateMachine();
		~StateMachine();

		/*
		Adds new state to the stack and eventually replaces previous one.
		@param newState smart ptr to the new state
		@param isReplacing if true covers previous state and displays itself, otherwise displays itself without covering previous state
		*/
		void addState(stateReference newState, bool is_replacing = true);

		//Removes state
		void removeState();

		//Gets pointer of the active state
		stateReference& getActiveState();
	};
}