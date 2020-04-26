#include "Places.h"

MP::Places::Places()
{
}

void MP::Places::update()
{
}

void MP::Places::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
}
