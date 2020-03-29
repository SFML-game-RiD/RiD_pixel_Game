#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "TaskManager.h"

namespace MP
{
	class Camera
	{
	private:

		sf::View _view;

		sf::RenderWindow _window;

		void _zoom_in();

		void _zoom_out();

	public:


		sf::RenderWindow & getWindow();

		void clearCamera();

		void drawFrame();

		void changeZoom(MP::TaskManager &aTaskManager);

		void changeCamera(sf::Vector2f coord);

	};
}
#endif // !_CAMERA_H_