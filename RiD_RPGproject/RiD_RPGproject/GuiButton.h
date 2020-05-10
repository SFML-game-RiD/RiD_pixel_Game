#pragma once
#include "Object.h"
#include "SoundManager.h"
#include "Sound.h"
#include "Engine/AssetManager.h"
#include "TaskManager.h"

namespace MP
{
	class GuiButton:public Object
	{
	private:

		sf::Text _a_text;///Stores button's text.

		bool _is_active;///Tells if button is active.

		bool _was_played;///Tells if sound was played.

		//Draws button.
		//@param aMainWindow game's window.
		void draw_button(sf::RenderWindow& aMainWindow);

		//Sets button state.
		//@param isActive new button's state.
		void set_button_active(bool isActive);

		MP::Sound _sound_player;

		void _song_procedure(MP::SoundManager& aSoundManager,MP::TaskManager &aMainTaskManager);

	public:

		//Button's constructor.
		//@param texturePtr button's texture.
		//@param buttonPositon button's coordinates.
		//@param relativelyTextPosition button's text position, relatively to button.
		//@param aFont game's font.
		//@param buttonName button's name.
		GuiButton(RiD::AssetManager& aAssetManager,sf::Vector2f buttonPosition, sf::Vector2f relativelyTextPosition, std::string buttonName);

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
		void update(SoundManager& aSoundManager, TaskManager& aTaskManager,bool isActive);

		//Draws button.
		//@param aMainWindow game's main window.
		void render(sf::RenderWindow& aMainWindow);
	};
}