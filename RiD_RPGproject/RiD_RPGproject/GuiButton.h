#ifndef _GUI_BUTTON_H
#define _GUIBUTTON_H_
#include "Obiect.h"

namespace MP
{
	class GuiButton:public Obiect
	{
	private:

		sf::Text _a_text;

		bool _is_active;
	public:

		GuiButton(sf::Texture* texturePtr,sf::Vector2f buttonPosition,sf::Font &aFont, std::string buttonName);

		void setPressed();

		sf::Text& getText();

		void setButtonActive(bool isActive);

		bool getButtonActive();
	};
}
#endif // !1