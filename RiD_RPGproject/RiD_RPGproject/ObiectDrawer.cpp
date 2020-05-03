#include "ObiectDrawer.h"
#include "MapElement.h"


void MP::ObiectDrawer::_draw_land(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{	
	std::vector<std::vector<MapElement*>>::iterator it;
	std::vector<MapElement*>::iterator it2;

	unsigned int counter = 0;

	std::vector<std::vector<MapElement*>> mapArray = aObiectManager.getMap().getMapArray();
	for (it = mapArray.begin(); it != mapArray.end(); it++)
	{
		for (it2 = mapArray[counter].begin(); it2 != mapArray[counter].end(); it2++)
		{
			(*it2)->getLandTile().render(mainWindow); //land drawing

			if ((*it2)->getPlace() != nullptr)
				(*it2)->getPlace()->render(mainWindow);//place drawing
		}
		counter++;
	}
}

void MP::ObiectDrawer::_draw_trees(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	std::list<Tree> * aTree = aObiectManager.getTreeList();
	std::list<Tree >::iterator iterator;
	iterator = aTree->begin();

	for (iterator; iterator != aTree->end(); iterator++)
		iterator->render(mainWindow);
}

void MP::ObiectDrawer::_draw_active_obiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{
	//drawing player and path icon (if exist);
	aObiectManager.getPlayer()->render(mainWindow);


	//drawing computer player
	std::list<MP::ComputerPlayerBandit> *computerPlayerList = aObiectManager.getComputerPlayerList();
	std::list<MP::ComputerPlayerBandit>::iterator it;
	it = computerPlayerList->begin();

	for (it; it != computerPlayerList->end(); it++)
		it->render(mainWindow);

}
void MP::ObiectDrawer::drawGame(TaskManager& aMainTaskManager, Camera& aGameCamera, ObiectManager& aObiectManager)
{
		//GAME DRAWING
		aGameCamera.changeViewToGame();
		_draw_land(aGameCamera.getWindow(), aObiectManager);
		_draw_active_obiects(aGameCamera.getWindow(), aObiectManager);
		_draw_trees(aGameCamera.getWindow(), aObiectManager);

		//GUI DRAWING
		aGameCamera.changeViewToGui();
		//Drawing map gui
		aObiectManager.getGuiManager().getMapGui()->render(aGameCamera.getWindow(), aObiectManager.getPlayer()->aItemsManager);
		//Drawing cursor
		aObiectManager.getCursor()->render(aGameCamera.getWindow());
}

void MP::ObiectDrawer::drawMenu(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, Camera& aGameCamera)
{
	aGameCamera.changeViewToGui();

	aObiectManager.getGuiManager().getGuiMainMenu()->render(aMainTaskManager,aGameCamera.getWindow());

	aObiectManager.getGuiManager().getGuiPlacesMenu()->render(aMainTaskManager, aGameCamera.getWindow());

	aObiectManager.getGuiManager().getGuiMarketPlace()->render(aMainTaskManager, aGameCamera.getWindow(),aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getPlayer()->getObiectCoord())->getPlace(),aObiectManager.getPlayer());

	aObiectManager.getCursor()->render(aGameCamera.getWindow());
}
