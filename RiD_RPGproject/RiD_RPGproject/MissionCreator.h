#pragma once
#include <iostream>
#include <map>
#include "Mission.h"
#include <random>

namespace MP
{
	class MissionCreator
	{
	private:

		std::mt19937 _random_number;

		std::map<std::string,std::shared_ptr<Mission>> _missions;
		
		void _set_mission(const char* missionPath, std::string missionName);

	public:

		MissionCreator();

		std::shared_ptr<Mission> getMission(char placeMark);
	};

}