#pragma once
#include <string>


namespace MP
{
	class Mission
	{

	private:

		char _employer;
		char _destination;
		std::string _action;
		unsigned int _fight_lvl;

		int _gold_award;
		int _wood_award;
		int _iron_award;
		int _food_award;
		int _spearman_award;
		int _swordsman_award;
		int _archer_award;

		int _gold_needs;
		int _wood_needs;
		int _iron_needs;
		int _food_needs;
		int _spearman_needs;
		int _swordsman_needs;
		int _archer_needs;

		std::string _start_message[5];
		std::string _destination_message[5];
		std::string _end_message[5];

		void _download_mission(const char* missionPath);
	public:

		Mission(const char* missionPath);

		char getDestination();
		char getEmployer();
		std::string getAction();
		unsigned int getFightLvl();

		std::string* getStartMessage();
		std::string* getEndMessage();
		std::string* getDestinationMessage();
	};

}