#pragma once
#include "Object.h"

namespace MP
{
	class GuiButton:public Object
	{
	private:

		sf::Text _a_text;///Stores button's text.

		bool _is_active;///Tells if button is active.

		//Draws button.
		//@param aMainWindow game's window.
		void draw_button(sf::RenderWindow& aMainWindow);

		//Sets button state.
		//@param isActive new button's state.
		void set_button_active(bool isActive);

	public:

		//Button's constructor.
		//@param texturePtr button's texture.
		//@param buttonPositon button's coordinates.
		//@param relativelyTextPosition button's text position, relatively to button.
		//@param aFont game's font.
		//@param buttonName button's name.
		GuiButton(sf::Texture* texturePtr,sf::Vector2f buttonPosition, sf::Vector2f relativelyTextPosition, sf::Font &aFont, std::string buttonName);

		//Returns button's text.
		//@return button's text.
		sf::Text& getText();

		//Return button's state.
		//@return button's state.
		bool getButtonIsActive();

		//Sets button's position.
		//@param newPosition new button's position.
		void setButtonPosition(sf::Vector2f newPostion);

		//Updates button.
		//@param isActive button's state.
		void update(bool isActive);

		//Draws button.
		//@param aMainWindow game's main window.
		void render(sf::RenderWindow& aMainWindow);
	};
}