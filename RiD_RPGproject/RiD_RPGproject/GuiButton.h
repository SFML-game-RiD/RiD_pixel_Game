#ifndef GUI_BUTTON_H
#define GUIBUTTON_H
#include "Obiect.h"

namespace MP
{
	class GuiButton:public Obiect
	{
	private:

		sf::Text _a_text;

		bool _is_active;

		void draw_button(sf::RenderWindow& aMainWindow);

		void set_button_active(bool isActive);

	public:

		GuiButton(sf::Texture* texturePtr,sf::Vector2f buttonPosition, sf::Vector2f relativelyTextPosition, sf::Font &aFont, std::string buttonName);

		void setPressed();

		sf::Text& getText();

		bool getButtonIsActive();

		void setButtonPosition(sf::Vector2f newPostion);

		void update(bool isActive);

		void render(sf::RenderWindow& aMainWindow);
	};
}
#endif // !1