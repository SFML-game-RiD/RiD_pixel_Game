#include "ObiectDrawer.h"



//############ WARNING, functions are not complete. ####################

void MP::ObiectDrawer::_draw_land(sf::RenderWindow& mainWindow, std::list<Land> & landList)
{	
	std::list<Land>::iterator it;
	it = landList.begin();

	for (int i = 0; i < landList.size(); i++)
	{
		mainWindow.draw(it->animationMaker.getObiectSprite());
		it++;
	}
}

void MP::ObiectDrawer::drawAllObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	
	//Drawing map
	_draw_land(mainWindow,aObiectManager.getLandList());

	//Drawing player
	drawActiveObiects(mainWindow, aObiectManager);





}

void MP::ObiectDrawer::drawActiveObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{



	mainWindow.draw(aObiectManager.getPlayer()->animationMaker.getObiectSprite());








}