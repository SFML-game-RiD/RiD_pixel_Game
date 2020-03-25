#include "ObiectDrawer.h"



//############ WARNING, functions are not complete. ####################

void MP::ObiectDrawer::drawAllObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{


	drawActiveObiects(mainWindow,aObiectManager);








}

void MP::ObiectDrawer::drawActiveObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{



	mainWindow.draw(aObiectManager.getPlayer()->animationMaker.getObiectSprite());








}