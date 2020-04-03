#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "TaskManager.h"

namespace MP
{
	class Camera
	{
	private:

		int _max_x_size;

		int _min_x_size;

		sf::View _view;

		sf::RenderWindow _window;

		void _zoom_in();

		void _zoom_out();

	public:

		Camera();

		sf::RenderWindow & getWindow();

		void clearCamera();

		void drawFrame();

		void changeZoom(MP::TaskManager &aTaskManager);

		void changeCamera(sf::Vector2f coord);

	};
}
#endif // !_CAMERA_H_