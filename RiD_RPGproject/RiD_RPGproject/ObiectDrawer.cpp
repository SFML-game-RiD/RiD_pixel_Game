#include "ObiectDrawer.h"
#include "MapElement.h"


void MP::ObiectDrawer::_draw_land(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager)
{	
	MapElement * tmp= aObiectManager.getMapElementHead();
	while (tmp != nullptr)
	{
			tmp->getLandTile().render(mainWindow); //land drawing

			if (tmp->getPlace() != nullptr)
				tmp->getPlace()->render(mainWindow);//place drawing

		tmp = tmp->getNextElement();
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
	std::list<MP::ComputerPlayer> *computerPlayerList = aObiectManager.getComputerPlayerList();
	std::list<MP::ComputerPlayer>::iterator it;
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

	aObiectManager.getGuiManager().getGuiMarketPlace()->render(aMainTaskManager, aGameCamera.getWindow(),aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getPlayer()->getObiectCoord(), aObiectManager.getMapElementHead())->getPlace(),aObiectManager.getPlayer());

	aObiectManager.getCursor()->render(aGameCamera.getWindow());
}
