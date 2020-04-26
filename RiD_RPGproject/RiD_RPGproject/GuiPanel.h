#pragma once
#include "Obiect.h"
namespace MP
{
	class GuiPanel :public Obiect
	{
	private:

		sf::Text _panel_title;

	public:

		GuiPanel(sf::Texture* texturePtr, sf::Font& aFont);

			void update(sf::Vector2f panelPosition, std::string panelName);

			void render(sf::RenderWindow &mainWindow);

	};
}
