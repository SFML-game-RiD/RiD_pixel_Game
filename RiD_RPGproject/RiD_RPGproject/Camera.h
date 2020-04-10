#ifndef _CAMERA_H_
#define _CAMERA_H_

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

//		sf::Vector2f _current_virtual_game_corner_position;

		void _zoom_in();

		void _zoom_out();

	public:	
		Camera();

		sf::RenderWindow & getWindow();

		void clearCamera();

		void drawFrame();

		void changeZoom(MP::TaskManager &aTaskManager);

		void changeCamera(sf::Vector2f coord);
		
		void changeViewToGame();//allows to update game

		void changeViewToGui();//updates gui

	};
}
#endif // !_CAMERA_H_