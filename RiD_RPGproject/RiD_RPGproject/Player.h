#ifndef PLAYER_H
#define PLAYER_H

#include "PawnObiect.h"
#include "Map.h"
#include "PathIcon.h"
#include <vector>
#include "TaskManager.h"

namespace MP
{
	class Player :public PawnObiect
	{
	private:

		sf::Vector2f checkingVector;//Variable used in player auto move procedure;

		MapElement* _path;

		sf::Texture * _a_path_icon_texture;

		std::vector<PathIcon> _a_path_icon;



		void _player_animation_right(sf::Clock& globalClock);

		void _player_animation_left(sf::Clock& globalClock);

		void _player_animation_up(sf::Clock& globalClock);

		void _player_animation_down(sf::Clock& globalClock);

		void _player_animation(sf::Clock& globalClock, TaskManager& aMainTaskManager);

		void _player_move(sf::Clock& globalClock, TaskManager& aMainTaskManager);

		void _player_automatic_move(Map& aMap, TaskManager& aTaskManager);

		void _set_path(MapElement*& newPath);

		void _player_auto_animation(sf::Clock& globalClock);

		void _player_auto_move(sf::Clock& globalClock);

		void _delete_player_path();

		void _mark_path();

		void _unmark_path();

		void _procedure_player_auto_or_normal_move(TaskManager& aMainTaskManager, sf::Clock& GameClock, MP::Map& aMap, sf::Vector2f &mouseGameCoord);

	public:

		Player(sf::Texture *texturePtr,sf::Texture *pathIconTexturePtr);

		void goToPlace(Map& aGameMap, TaskManager& aMainTaskManger);

		void update(TaskManager& aMainTaskManager, sf::Clock& GameClock, MP::Map& aMap, sf::Vector2f mouseGameCoord);

		void render(sf::RenderWindow &mainWindow);

	
	};


}
#endif