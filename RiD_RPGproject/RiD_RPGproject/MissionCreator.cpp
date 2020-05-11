#include "MissionCreator.h"
#include "Time.h"
#include "Engine/ConfigurationLoader.h"

void MP::MissionCreator::_set_mission(const char* missionPath, std::string missionName)
{
	std::shared_ptr<Mission> tmp = std::make_shared<Mission>(missionPath);

	_missions[missionName] = tmp;
}

MP::MissionCreator::MissionCreator()
{
	_random_number.seed(time(NULL));
	_set_mission("missions/town_medicine.ini", "townmedicine");
}

std::shared_ptr<MP::Mission> MP::MissionCreator::getMission(char placeMark)
{
	std::string missionName;

	if (placeMark == RiD::ConfigurationLoader::getStringData("castle", "mark")[0])
	{

	}
	if (placeMark == RiD::ConfigurationLoader::getStringData("town", "mark")[0])
	{
		missionName = "townmedicine";
	}
	if (placeMark == RiD::ConfigurationLoader::getStringData("village", "mark")[0])
	{

	}
	return _missions.at(missionName);
}
