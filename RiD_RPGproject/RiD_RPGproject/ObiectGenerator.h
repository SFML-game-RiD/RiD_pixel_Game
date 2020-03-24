#ifndef _OBIECTGENERATOR_H_
#define _OBIECTGENERATOR_H_

#include "ObiectDrawer.h"
#include "ObiectManager.h"

namespace MP
{
	class ObiectGenerator
	{
	private:


		void _generate_player(ObiectManager& aObiectManager);

	public:

		void generateObiects(ObiectManager & aObiectManager);

	};
}
#endif