#include "ObiectDrawer.h"




void MP::ObiectDrawer::drawAllObiects(sf::RenderWindow& mainWindow)
{

	drawActiveObiects(mainWindow);

	ObiectContainer* tmp = _static_obiects_list;
	while (tmp != nullptr)
	{
		mainWindow.draw(tmp->aObiect->objSprite);
		tmp = tmp->nextContainer;
	}
}

void MP::ObiectDrawer::drawActiveObiects(sf::RenderWindow& mainWindow)
{
	ObiectContainer* tmp = _active_obiects_list;
	while (tmp != nullptr)
	{
		mainWindow.draw(tmp->aObiect->objSprite);
		tmp = tmp->nextContainer;
	}
}

void MP::ObiectDrawer::addObiect(ObiectContainer*& head, ObiectContainer*& obiect)
{
	if (head == nullptr)
		head = obiect;
	else
		addObiect(head->nextContainer, obiect);
}

void MP::ObiectDrawer::deleteObiects(ObiectContainer*& head)
{
	if (head == nullptr)
		return;
	else
	{
		deleteObiects(head->nextContainer);
		delete head;
	}

}

MP::ObiectContainer*& MP::ObiectDrawer::getActiveObiectsList()
{
	return _active_obiects_list;
}

MP::ObiectContainer*& MP::ObiectDrawer::getStaticObiectsList()
{
	return _static_obiects_list;
}

