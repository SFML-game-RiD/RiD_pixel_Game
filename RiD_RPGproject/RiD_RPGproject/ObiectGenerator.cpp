#include "ObiectGenerator.h"
#include "Player.h"
#include "ActiveObiect.h"
#include "MapAnimation.h"
#include "Land.h"
#include "Engine/ConfigurationLoader.h"

void MP::ObiectGenerator::_generate_map(ObiectManager& aObiectManager)
{
	int columns;
	int rows;
	
	
	
	
	
	
	Land * tmp=new Land;

	aObiectManager.addObiect(tmp);

}

void MP::ObiectGenerator::_generate_player(ObiectManager& aObiectManager)
{

	std::shared_ptr<MP::Player> tmp = std::make_shared< Player >();

	aObiectManager.addObiect(tmp);
}

void MP::ObiectGenerator::generateObiects(ObiectManager& aObiectManager)
{
	_generate_map(aObiectManager);
	_generate_player(aObiectManager);
}
