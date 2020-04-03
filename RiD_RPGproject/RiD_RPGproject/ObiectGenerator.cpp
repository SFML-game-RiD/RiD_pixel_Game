#include <fstream>
#include "ObiectGenerator.h"
#include "Player.h"
#include "ActiveObiect.h"
#include "MapAnimation.h"
#include "Land.h"
#include "Engine/ConfigurationLoader.h"

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
				Tree* tmpTree = new Tree(&_a_asset_manager.getTexture("tree"),tmpCoord);
				aObiectManager.getTreeList()->push_back(*tmpTree);
				counter--;
	
			}

		}
		tmp = tmp->getNextElement();
	}
}

void MP::ObiectGenerator::_generate_player(ObiectManager& aObiectManager)
{

	std::shared_ptr<MP::Player> tmp = std::make_shared< Player >(&_a_asset_manager.getTexture("player"));

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
			}
			y += blockLength;
		}
	}
	aObiectManager.getMap().createWeb();
}

void MP::ObiectGenerator::_generate_computer_player(ObiectManager& aObiectManager)
{
}

MP::ObiectGenerator::ObiectGenerator()
{
	_random_number.seed(time(NULL));
}

void MP::ObiectGenerator::generateObiects(ObiectManager& aObiectManager)
{
	_a_asset_manager.setTexture("tree", "img/mpimg/mptree.png");
	_a_asset_manager.setTexture("land", "img/mpimg/mpgrass.png");
	_a_asset_manager.setTexture("player", "img/mpimg/mpcharacter.png");
	_a_asset_manager.setTexture("village", "img/mpimg/places/mpvillage.png");
	_a_asset_manager.setTexture("town", "img/mpimg/places/mptown.png");
	_a_asset_manager.setTexture("castle", "img/mpimg/places/mpcastle.png");

	_generate_map(aObiectManager);
	_generate_trees(aObiectManager);
	_generate_player(aObiectManager);
}
