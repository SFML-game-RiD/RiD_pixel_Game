#include "StateMachine.h"

namespace RiD
{
	StateMachine::StateMachine() {}
	StateMachine::~StateMachine() {}

	void StateMachine::addState(stateReference newState, bool is_replacing)
	{
		this->_isAdding = true;
		this->_isReplacing = is_replacing;

		this->_newState = std::move(newState);
	}

	void StateMachine::removeState()
	{
		this->_isRemoving = true;

		//TODO 
	}
	stateReference& StateMachine::getActiveState()
	{
		return this->_stackOfStates.top();
	}
}
