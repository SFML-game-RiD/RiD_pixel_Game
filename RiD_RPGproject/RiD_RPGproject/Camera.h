#ifndef CAMERA_H
#define CAMERA_H

#include "TaskManager.h"
#include "GuiManager.h"

namespace MP
{
	class Camera
	{
	private:

		int _max_x_size;

		int _min_x_size;

		sf::RenderWindow _window;

		sf::View _game_view;

		sf::View _gui_view;

		void _zoom_in();

		void _zoom_out();

		void _change_zoom(MP::TaskManager& aTaskManager);

		void _change_camera(sf::Vector2f coord);

	public:	

		Camera();

		sf::RenderWindow & getWindow();

		void clearCamera();

		void drawFrame();
		
		void changeViewToGame();//allows to update game

		void changeViewToGui();//updates gui

		void update(sf::Vector2f newFocusCoord, TaskManager &aMainTaskManager);

	};
}
#endif // !_CAMERA_H_