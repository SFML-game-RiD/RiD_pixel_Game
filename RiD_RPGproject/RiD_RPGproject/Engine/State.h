#pragma once

namespace RiD
{
	class State
	{
	public:
		State() {}
		~State() {}

		//Initializes states
		virtual void Init() = 0;
		//Updates
		virtual void Update() = 0;
		//Draws user interface
		virtual void DrawUI(float deltaTime) = 0;
	};
}

