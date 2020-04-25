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

	public:

		GuiButton(sf::Texture* texturePtr,sf::Vector2f buttonPosition, sf::Vector2f relativelyTextPosition, sf::Font &aFont, std::string buttonName);

		void setPressed();

		sf::Text& getText();

		void setButtonActive(bool isActive);

		bool getButtonActive();

		void drawButton(sf::RenderWindow& aMainWindow);

		void setButtonPosition(sf::Vector2f newPostion);


		void update();

		void render();
	};
}
#endif // !1