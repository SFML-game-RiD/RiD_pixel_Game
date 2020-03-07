#pragma once

#include "SFML/Window/Keyboard.hpp"
#include <iostream>
#include <map>

namespace RiD
{
	class InputManager
	{
	private:
		enum class _inputType{KeyboardInput, MouseInput /*JoysticInput*/ };
	public:
		InputManager();
		~InputManager();
	};
}