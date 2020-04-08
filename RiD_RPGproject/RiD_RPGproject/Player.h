#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Move.h"
#include "PawnObiect.h"
#include "Map.h"
#include "PathIcon.h"
#include <vector>

namespace MP
{
	class Player :public PawnObiect
	{
	private:

		MapElement* _path;

		sf::Texture * _a_path_icon_texture;

		std::vector<PathIcon> _a_path_icon;

		void _player_animation_right(sf::Clock& globalClock);

		void _player_animation_left(sf::Clock& globalClock);

		void _player_animation_up(sf::Clock& globalClock);

		void _player_animation_down(sf::Clock& globalClock);



	public:

		TaskManager aPlayerTaskManager;

		Player(sf::Texture *texturePtr,sf::Texture *pathIconTexturePtr);

		//############ move animation ##############

		void playerAnimation(sf::Clock& globalClock, MP::TaskManager& aTaskManager);

		void playerAutomaticMove(Map &aMap,TaskManager &aTaskManager);

		void setPath(MapElement*& newPath);

		MapElement*& getPath();

		void playerAutoAnimation(sf::Clock& globalClock);

		void playerAutoMove(sf::Clock& globalClock);

		void deletePlayerPath();

		void markPath();

		void unmarkPath();

		std::vector<PathIcon>& getPathIcon();
	};


}
#endif