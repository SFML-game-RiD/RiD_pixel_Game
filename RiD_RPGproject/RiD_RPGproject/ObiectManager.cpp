#include <SFML/Graphics.hpp>
#include "ObiectManager.h"
#include "ObiectContainer.h"
#include "Player.h"

MP::ObiectManager::ObiectManager()
{
	activeObiectList = nullptr;
	staticObiectList = nullptr;
}

MP::ObiectManager::~ObiectManager()
{
	deleteObiects(activeObiectList);
	deleteObiects(staticObiectList);
}

void MP::ObiectManager::drawAllObiects(sf::RenderWindow & mainWindow)
{
	
	drawActiveObiects(mainWindow);
	
	ObiectContainer* tmp = staticObiectList;
	while (tmp != nullptr)
	{
		mainWindow.draw(tmp->aObiect->objSprite);
		tmp = tmp->nextContainer;
	}
}

void MP::ObiectManager::drawActiveObiects(sf::RenderWindow & mainWindow)
{
	ObiectContainer* tmp = activeObiectList;
	while (tmp!=nullptr)
	{
		mainWindow.draw(tmp->aObiect->objSprite);
		tmp = tmp->nextContainer;
	}
}

void MP::ObiectManager::addObiect(ObiectContainer *& head, ObiectContainer *& obiect)
{
	if (head == nullptr)
		head = obiect;
	else
		addObiect(head->nextContainer, obiect);
}

void MP::ObiectManager::deleteObiects(ObiectContainer*& head)
{
	if (head == nullptr)
		return;
	else
	{
		deleteObiects(head->nextContainer);
		delete head;
	}
	
}

void MP::ObiectManager::generateObiects()
{
	Obiect * tmp = new Player;
	ObiectContainer* tmpC = new ObiectContainer(tmp);
	this->addObiect(this->activeObiectList, tmpC);
}
