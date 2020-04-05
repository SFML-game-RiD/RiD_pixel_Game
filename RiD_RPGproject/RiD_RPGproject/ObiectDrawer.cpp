#include "ObiectDrawer.h"
#include "MapElement.h"


//############ WARNING, functions are not complete. ####################

void MP::ObiectDrawer::_draw_land(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{	
	MapElement * tmp= aObiectManager.getMapElementHead();
	while (tmp != nullptr)
	{
			mainWindow.draw(tmp->getLandTile().aAnimation.getObiectSprite()); //land drawing.
			
			if (tmp->getPlace() != nullptr)
			mainWindow.draw(tmp->getPlace()->aAnimation.getObiectSprite());//place drawing.
		
		tmp = tmp->getNextElement();
	}
}

void MP::ObiectDrawer::_draw_trees(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	std::list<Tree> * aTree = aObiectManager.getTreeList();
	std::list<Tree >::iterator iterator;
	iterator = aTree->begin();

	for(int i =0;i<aTree->size();i++)
	{
		mainWindow.draw(iterator->aAnimation.getObiectSprite());
		iterator++;
	}
}

void MP::ObiectDrawer::drawAllObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	
	//Drawing map
	_draw_land(mainWindow,aObiectManager);

	//Drawing player
	drawActiveObiects(mainWindow, aObiectManager);

	//Drwaing Trees
	_draw_trees(mainWindow, aObiectManager);




}

void MP::ObiectDrawer::drawActiveObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{



	mainWindow.draw(aObiectManager.getPlayer()->aAnimation.getObiectSprite());
	
	
	mainWindow.draw(aObiectManager.getComputerPlayer()->aAnimation.getObiectSprite());








}