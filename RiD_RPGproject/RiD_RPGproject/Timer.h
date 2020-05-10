#pragma once
#include <SFML/Graphics.hpp>

namespace MP
{
	class Timer
	{	
	private:

		sf::Time _next_active;

		sf::Time _last_active;

		bool _is_timer_rdy;

		

	public:

		Timer();

		bool timeControl(sf::Clock & gameClock,sf::Time breakTime);

		void setTimer(sf::Clock& gameClock, sf::Time breakTime);
	
	};
}