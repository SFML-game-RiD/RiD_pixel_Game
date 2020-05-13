#pragma once
#include <vector>
#include "PawnObject.h"
#include "Map.h"
#include "PathIcon.h"
#include "TaskManager.h"
#include "SoundManager.h"
#include "MissionCreator.h"

namespace MP
{
	class Player :public PawnObject
	{
	private:

		sf::Vector2f checkingVector;///Saved postion of first clicked block.

		MapElement* _path;///Player's path, generated from auto move procedure.

		sf::Texture * _a_path_icon_texture;///Stores path's texture.

		std::vector<PathIcon> _a_path_icon;///Stores path's icon.

	 	MissionCreator _a_mission_creator;

		std::shared_ptr<Places> _current_place;///Stores current place which interact witch player.

		std::shared_ptr<Places> _destination_place;

		std::shared_ptr<Places> _employer_place;

		std::shared_ptr<Mission> _current_mision;

		std::string message[12];

		//Changes player's sprite.
		//@param globalClock games'clock.
		void _player_animation_right(sf::Clock& globalClock);

		//Changes player's sprite.
		//@param globalClock games'clock.
		void _player_animation_left(sf::Clock& globalClock);

		//Changes player's sprite.
		//@param globalClock games'clock.
		void _player_animation_up(sf::Clock& globalClock);

		//Changes player's sprite.
		//@param globalClock games'clock.
		void _player_animation_down(sf::Clock& globalClock);

		//Changes player's sprite.
		//@param globalClock games'clock.
		void _player_animation_idle(sf::Clock& globalClock);

		//Starts player's animation. 
		//@param globalClock game's clock.
		//@param aMainTaskManager game's task manager.
		void _player_animation(sf::Clock& globalClock, TaskManager& aMainTaskManager);

		//Starts player;s move. 
		//@param globalClock game's clock.
		//@param aMainTaskManager game's task manager.
		void _player_move(sf::Clock& globalClock, TaskManager& aMainTaskManager);

		//Starts player's auto move. 
		//@param aMap game's map.
		//@param aMainTaskManager game's task manager.
		void _player_automatic_move(Map& aMap, TaskManager& aMainTaskManager);

		//Sets new path.
		//@param newPath new path head.
		void _set_path(MapElement*& newPath);

		//Starts player's auto animation.
		//@param globalClock game's clock.
		void _player_auto_animation(sf::Clock& globalClock);

		//Starts player's auto move.
		//@param globalClock game's clock.
		void _player_auto_move(sf::Clock& globalClock);

		//Delets player's path.
		void _delete_player_path();

		//Creates path icon.
		void _mark_path();

		//Delets path icon.
		void _unmark_path();

		//Starts move procedure according to task manager.
		//@param aMainTaskManager game's task manager.
		//@param GameClock game's clock.
		//@param aMap game's map.
		//@param mouseGameCoord mouse's game coordination.
		void _procedure_player_auto_or_normal_move(TaskManager& aMainTaskManager, sf::Clock& GameClock, MP::Map& aMap, sf::Vector2f &mouseGameCoord);

		void _song_procedure(sf::Clock& gameClock, MP::SoundManager& aSoundManager, TaskManager& aMainTaskManager);

		void _mission_procedure(TaskManager& aMainTaskManager, Map& gameMap, SoundManager& aSoundManager);

	public:

		//Player's constructor.
		//@param texturePtr player's texture.
		//@param pathIconTexturePtr path's texture.
		Player(sf::Texture *texturePtr,sf::Texture *pathIconTexturePtr);

		//Opens place's menu.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void goToPlace(Map& gameMap, TaskManager& aMainTaskManger);

		//Returns current place.
		//return current place.
		std::shared_ptr<Places> & getCurrentPlace();

		std::string* getMessage();

		//Updates player.
		//@param aMainTaskManager game's task manager.
		//@param gameClock game's clock.
		//@param gameMap game's map.
		//@param mouseGameCoord
		void update(SoundManager& aSoundManager, TaskManager& aMainTaskManager, sf::Clock& gameClock, MP::Map& gamesMap, sf::Vector2f mouseGameCoord);

		//Draws player.
		void render(sf::RenderWindow &mainWindow);

	
	};


}