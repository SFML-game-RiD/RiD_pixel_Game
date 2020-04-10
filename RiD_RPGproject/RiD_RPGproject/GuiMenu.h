#ifndef _GUIMENU_H_
#define _GUIMENU_H_
#include <SFML/Graphics.hpp>
#include "Obiect.h"
#include "GuiButton.h"
#include "Cursor.h"
#include "TaskManager.h"

namespace MP
{
	class GuiMenu :public Obiect
	{
		sf::Vector2f _start_button_coord;
		sf::Vector2f _save_button_coord;
		sf::Vector2f _load_button_coord;
		sf::Vector2f _exit_button_coord;

		std::unique_ptr<GuiButton> _start_button;
		std::unique_ptr<GuiButton> _save_button;
		std::unique_ptr<GuiButton> _load_button;
		std::unique_ptr<GuiButton> _exit_button;

		bool	_check_if_start_pressed(Cursor& aCursor);
		bool	_check_if_save_pressed(Cursor& aCursor);
		bool	_check_if_load_pressed(Cursor& aCursor);
		bool	_check_if_exit_pressed(Cursor& aCursor);


	public:

		GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture);

		void drawMenu(Cursor& aCursor,sf::RenderWindow& aMainWindow);

	};
}
#endif // !_GUIMENU_H_
