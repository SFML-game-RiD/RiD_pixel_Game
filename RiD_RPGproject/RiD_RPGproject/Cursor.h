#ifndef CURSOR_H
#define CURSOR_H
#include "SFML/Graphics.hpp"
#include "Obiect.h"
#include "Camera.h"
#include "TaskManager.h"

namespace MP
{
	class Cursor: public Obiect
	{
	private:
			
		sf::Vector2f _game_coord;

		sf::Vector2f _gui_coord;

		void _update_cursor(TaskManager& aMainTaskManager, Camera& aCamera);

		void _check_if_player_clicked(TaskManager& aTaskManager, Camera& aCamera);

	public:

		Cursor(sf::Texture* texturePtr);

		void setGameCoord(sf::Vector2f gameCoord);
		
		sf::Vector2f getGameCoord();

		void setGuiCoord(sf::Vector2f guiCoord);

		sf::Vector2f getGuiCoord();

		void update(TaskManager& aMainTaskManager, Camera& aCamera);

		void render(sf::RenderWindow &mainWindow);
	};
}
#endif // !_CURSOR_H_