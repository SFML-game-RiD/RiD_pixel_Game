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
				Tree* tmpTree = new Tree(tmpCoord);
				aObiectManager.getTreeList()->push_back(*tmpTree);
				counter--;


				//std::pair<int, int> tmpCoord = tmp->getLandTile().getObiectCoord();
				/*tmpCoord.first+=_random_number() % spawnRange;
				tmpCoord.second += _random_number() % spawnRange;
				Tree *tmpTree=new Tree(tmpCoord);
				aObiectManager.getTreeList()->push_back(*tmpTree);
				counter--;*/
			}

		}
		tmp = tmp->getNextElement();
	}
}

void MP::ObiectGenerator::_generate_player(ObiectManager& aObiectManager)
{

	std::shared_ptr<MP::Player> tmp = std::make_shared< Player >();

	aObiectManager.addObiect(tmp);
}

MP::ObiectGenerator::ObiectGenerator()
{
	_random_number.seed(time(NULL));
}

void MP::ObiectGenerator::generateObiects(ObiectManager& aObiectManager)
{
	_generate_trees(aObiectManager);
	_generate_player(aObiectManager);
}
