#pragma once

#include "SFML/Graphics.hpp"
#include "State.h"
#include "AssetManager.h"

#define MENU_ITEMS 4 //New game, load, options, exit

namespace RiD
{
	class MenuState
		:public State
	{
	private:
		AssetManager assets;

	};
}