#include "ObiectGenerator.h"
#include "Player.h"
#include "ObiectContainer.h"
#include "ActiveObiect.h"

void MP::ObiectGenerator::generateObiects(ObiectManager& aObiectManager, ObiectDrawer& aObiectDrawer)
{
	std::shared_ptr<MP::Player> tmp = std::make_shared< Player >();

	aObiectManager.addObiect(tmp);

	ObiectContainer* tmpC = new ObiectContainer(tmp);
	aObiectDrawer.addObiect(aObiectDrawer.getActiveObiectsList(), tmpC);
}
