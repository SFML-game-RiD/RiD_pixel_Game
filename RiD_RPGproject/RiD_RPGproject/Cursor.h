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

	public:

		void setGameCoord(sf::Vector2f gameCoord);
		
		sf::Vector2f getGameCoord();

		void setGuiCoord(sf::Vector2f guiCoord);

		sf::Vector2f getGuiCoord();

		Cursor(sf::Texture* texturePtr);

		void updateCursor(TaskManager& aMainTaskManager, Camera& aCamera);

		void checkIfPlayerClicked(TaskManager& aTaskManager, Camera& aCamera);


		void update(TaskManager& aMainTaskManager, Camera& aCamera);

		void render();
	};
}
#endif // !_CURSOR_H_