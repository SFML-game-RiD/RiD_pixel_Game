#include <fstream>
#include "ObiectGenerator.h"
#include "Player.h"
#include "ActiveObiect.h"
#include "Animation.h"
#include "Land.h"
#include "Engine/ConfigurationLoader.h"
#include "ComputerPlayer.h"

void MP::ObiectGenerator::_generate_trees(ObiectManager& aObiectManager)
{

	MP::MapElement *tmp = aObiectManager.getMapElementHead();
	char controlMark = RiD::ConfigurationLoader::getStringData("game settings", "treeWallMark")[0];
	while (tmp != nullptr)
	{
		if (tmp->getMark() == controlMark)
		{
			int counter = RiD::ConfigurationLoader::getIntData("game settings","numberOfTrees");
			int spawnRange = RiD::ConfigurationLoader::getIntData("game settings","blockLength");
			spawnRange -= 10;
			while (counter != 0)
			{
				sf::Vector2f tmpCoord = tmp->getLandTile().getObiectCoord();
				tmpCoord.x += _random_number() % spawnRange;
				tmpCoord.y += _random_number() % spawnRange;

				float newScale =(( _random_number() % 50)*0.01)+0.8;
				

				std::shared_ptr<Tree> tmpTree = std::make_shared<Tree>(&_a_asset_manager.getTexture("tree"),tmpCoord,newScale);
				aObiectManager.getTreeList()->push_back(*tmpTree);
				counter--;
	
			}

		}
		tmp = tmp->getNextElement();
	}
}

void MP::ObiectGenerator::_generate_player(ObiectManager& aObiectManager)
{

	std::shared_ptr<MP::Player> tmp = std::make_shared< Player >(&_a_asset_manager.getTexture("player"), &_a_asset_manager.getTexture("pathicon"));

	aObiectManager.addObiect(tmp);
}

void MP::ObiectGenerator::_generate_map(ObiectManager& aObiectManager)
{
	std::fstream mapFile;
	mapFile.open("worldmaps/worldmap1.txt", std::ios::in);

	std::string line;

	int blockLength = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");
	int y = 0;

	while (mapFile)
	{
		int x = 0;
		std::getline(mapFile, line);

		if (mapFile)
		{
			for (int i = 0; i < line.length(); i++)
			{
				MapElement* tmp = new MapElement(_a_asset_manager,x, y, line[i]);
				aObiectManager.getMap().addMapElement(aObiectManager.getMapElementHead(), tmp);
				x += blockLength;
				aObiectManager.getMap().setLastElementCoord(tmp->getLandTile().getObiectCoord());
			}
			y += blockLength;
		}
	}
	aObiectManager.getMap().createWeb();
}

void MP::ObiectGenerator::_generate_computer_player(ObiectManager& aObiectManager)
{
	int computerPlayerAmmount = RiD::ConfigurationLoader::getIntData("computer player", "numberOfPlayers");

	while (computerPlayerAmmount != 0)
	{
		std::shared_ptr<ComputerPlayer> tmp= std::make_shared<ComputerPlayer>(&_a_asset_manager.getTexture("player"));

		aObiectManager.addObiect(*tmp);

		computerPlayerAmmount--;
	}

}

void MP::ObiectGenerator::_generate_cursor(ObiectManager& aObiectManager)
{
	std::shared_ptr<Cursor> tmp = std::make_shared<Cursor>(&_a_asset_manager.getTexture("cursor"));
	aObiectManager.setCursor(tmp);

}

void MP::ObiectGenerator::_generate_gui(ObiectManager& aObiectManager)
{
	//WORK IN PROGRESS

	//creating map gui
	aObiectManager.getGuiManager().getMapGui() = std::make_unique<MapGui>(&_a_asset_manager.getTexture("mapgui"));


	//creating main menu
	aObiectManager.getGuiManager().getGuiMainMenu() = std::make_unique<GuiMenu>(&_a_asset_manager.getTexture("menu"), &_a_asset_manager.getTexture("button"));


	//creating places menu
	//aObiectManager.getGuiManager().getGuiPlacesMenu() = std::make_unique<GuiMenu>(&_a_asset_manager.getTexture("menu"));
}

MP::ObiectGenerator::ObiectGenerator()
{
	_random_number.seed(time(NULL));
}

void MP::ObiectGenerator::generateObiects(ObiectManager& aObiectManager)
{
	_a_asset_manager.setTexture("tree", "img/mpimg/mptree.png");
	_a_asset_manager.setTexture("land", "img/mpimg/mpgrass8.png");
	_a_asset_manager.setTexture("player", "img/mpimg/mpcharacter.png");
	_a_asset_manager.setTexture("village", "img/mpimg/places/mpvillage.png");
	_a_asset_manager.setTexture("town", "img/mpimg/places/mptown.png");
	_a_asset_manager.setTexture("castle", "img/mpimg/places/mpcastle.png");
	_a_asset_manager.setTexture("cursor", "img/mpimg/icons/hand.png");
	_a_asset_manager.setTexture("pathicon", "img/mpimg/icons/move.png");
	_a_asset_manager.setTexture("mapgui", "img/GUI/rid_map_gui.png");
	_a_asset_manager.setTexture("menu", "img/GUI/rid_main_menu.png");
	_a_asset_manager.setTexture("button", "img/GUI/button.png");

	_generate_map(aObiectManager);
	_generate_trees(aObiectManager);
	_generate_player(aObiectManager);
	_generate_computer_player(aObiectManager);
	_generate_cursor(aObiectManager);
	_generate_gui(aObiectManager);
}
