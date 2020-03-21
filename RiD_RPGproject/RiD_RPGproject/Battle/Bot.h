#pragma once

#include "Character.h"

namespace RTB
{
	class Bot
		:public Character
	{
	private:
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
		HPBar* _hp_bar = nullptr;
	public:
		Bot(sf::Texture texture);
		~Bot();
	};
}