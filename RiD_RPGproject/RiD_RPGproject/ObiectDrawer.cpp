#include "ObiectDrawer.h"
#include "MapElement.h"


//############ WARNING, functions are not complete. ####################

void MP::ObiectDrawer::_draw_land(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{	
	MapElement * tmp= aObiectManager.getMapElementHead();
	while (tmp != nullptr)
	{
		mainWindow.draw(tmp->getLandTile().animationMaker.getObiectSprite());
		tmp = tmp->getNextElement();
	}
}

void MP::ObiectDrawer::drawAllObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	
	//Drawing map
	_draw_land(mainWindow,aObiectManager);

	//Drawing player
	drawActiveObiects(mainWindow, aObiectManager);





}

void MP::ObiectDrawer::drawActiveObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{



	mainWindow.draw(aObiectManager.getPlayer()->animationMaker.getObiectSprite());








}