#ifndef _GUI_BUTTON_H
#define _GUIBUTTON_H_
#include "Obiect.h"

namespace MP
{
	class GuiButton:public Obiect
	{
	public:

		GuiButton(sf::Texture* texturePtr,sf::Vector2f buttonPosition);

		void setPressed();

	};
}
#endif // !1