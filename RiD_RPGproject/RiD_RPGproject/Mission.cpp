#include "Mission.h"
#include <fstream>
#include "simpleini-master/SimpleIni.h"

void MP::Mission::_download_mission(const char *missionPath)
{
	CSimpleIniA ini;
	ini.SetUnicode();

		if (ini.LoadFile(missionPath) == NULL)
		{
			//arguments
			const char* pVal1 = ini.GetValue("mission arguments","employer");
			_employer=pVal1[0];

			const char* pVal2 = ini.GetValue("mission arguments", "destination");
			_destination = pVal2[0];
			const char* pVal3 = ini.GetValue("mission arguments", "action");
			_action = pVal3;

			const char* pVal4 = ini.GetValue("mission arguments", "fight_level");
			_fight_lvl = atoi(pVal4);


			//awards
			const char* pVal5 = ini.GetValue("reward","gold");
			_gold_award = atoi(pVal5);
			const char* pVal6= ini.GetValue("reward", "iron");
			_iron_award = atoi(pVal6);
			const char* pVal7= ini.GetValue("reward", "wood");
			_wood_award = atoi(pVal7);
			const char* pVal8= ini.GetValue("reward", "food");
			_food_award = atoi(pVal8);
			const char* pVal9= ini.GetValue("reward", "spearman");
			_spearman_award = atoi(pVal9);
			const char* pVal10= ini.GetValue("reward", "swordsman");
			_swordsman_award = atoi(pVal10);
			const char* pVal11= ini.GetValue("reward", "archer");
			_archer_award = atoi(pVal11);

			//needs
			const char* pVal12 = ini.GetValue("needs", "gold");
			_gold_needs = atoi(pVal12);
			const char* pVal13 = ini.GetValue("needs", "iron");
			_iron_needs = atoi(pVal13);
			const char* pVal14= ini.GetValue("needs", "wood");
			_wood_needs = atoi(pVal14);
			const char* pVal15 = ini.GetValue("needs", "food");
			_food_needs = atoi(pVal15);
			const char* pVal16 = ini.GetValue("needs", "spearman");
			_spearman_needs = atoi(pVal16);
			const char* pVal117 = ini.GetValue("needs", "swordsman");
			_swordsman_needs = atoi(pVal117);
			const char* pVal118 = ini.GetValue("needs", "archer");
			_archer_needs = atoi(pVal118);
			

			for(int i=1;i<6;i++)
			{
				std::string tmp = std::to_string(i); 
				std::string key = (std::string("line") + tmp);
				const char* pVal0 = ini.GetValue("start message", &key[0]);
				std::string tmp2 = pVal0;
				_start_message[(i-1)] = tmp2;
			}
			for(int i=1;i<6;i++)
			{
				std::string tmp = std::to_string(i);
				std::string key = (std::string("line") + tmp);
				const char* pVal0 = ini.GetValue("end message", &key[0]);
				std::string tmp2 = pVal0;
				_end_message[(i - 1)] = tmp2;
			}
			for(int i=1;i<6;i++)
			{
				std::string tmp = std::to_string(i);
				std::string key = (std::string("line") + tmp);
				const char* pVal0 = ini.GetValue("destination message", &key[0]);
				std::string tmp2 = pVal0;
				_destination_message[(i - 1)] = tmp2;
			}
		}
	
}

MP::Mission::Mission(const char* missionPath)
{
	
	_download_mission(missionPath);
}

char MP::Mission::getDestination()
{
	return _destination;
}

char MP::Mission::getEmployer()
{
	return _employer;
}

std::string MP::Mission::getAction()
{
	return _action;
}

unsigned int MP::Mission::getFightLvl()
{
	return _fight_lvl;
}

std::string* MP::Mission::getStartMessage()
{
	return _start_message;
}

std::string* MP::Mission::getEndMessage()
{
	return _end_message;
}

std::string* MP::Mission::getDestinationMessage()
{
	return _destination_message;
}
