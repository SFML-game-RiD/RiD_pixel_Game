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

void MP::ObiectDrawer::drawAllObiects(Camera& aGameCamera, ObiectManager& aObiectManager)
{
	//GAME DRAWING
	aGameCamera.changeViewToGame();


	//Drawing map
	_draw_land(aGameCamera.getWindow(),aObiectManager);

	//Drawing player
	_draw_active_obiects(aGameCamera.getWindow(), aObiectManager);

	//Drwaing trees
	_draw_trees(aGameCamera.getWindow(), aObiectManager);

	//GAME DRAWING END

	//GUI DRAWING
	aGameCamera.changeViewToGui();

	_draw_gui_obiects(aGameCamera.getWindow(), aObiectManager);

	aGameCamera.changeViewToGame();
	//GUI DRAWING END
}

void MP::ObiectDrawer::_draw_gui_obiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	//Drawing map gui
	_draw_map_gui(mainWindow,aObiectManager);

	//Drawing cursor
	_draw_cursor(mainWindow, aObiectManager);
}

void MP::ObiectDrawer::_draw_active_obiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{


	//drawing player and path icon ( if exist);
	mainWindow.draw(aObiectManager.getPlayer()->aAnimation.getObiectSprite());
	std::vector<PathIcon> tmpPathCopy = aObiectManager.getPlayer()->getPathIcon();
	for (int i = 0; i < tmpPathCopy.size(); i++)
	{
		mainWindow.draw(tmpPathCopy[i].aAnimation.getObiectSprite());
	}

	//drawing computer player
	std::list<MP::ComputerPlayer> *computerPlayerList = aObiectManager.getComputerPlayerList();
	std::list<MP::ComputerPlayer>::iterator it;
	it = computerPlayerList->begin();

	for (it; it != computerPlayerList->end(); it++)
	{
		mainWindow.draw(it->aAnimation.getObiectSprite());
	}







}

void MP::ObiectDrawer::_draw_map_gui(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	mainWindow.draw(aObiectManager.getGuiManager().getMapGui()->aAnimation.getObiectSprite());
}

void MP::ObiectDrawer::_draw_cursor(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	mainWindow.draw(aObiectManager.getCursor()->aAnimation.getObiectSprite());
}
