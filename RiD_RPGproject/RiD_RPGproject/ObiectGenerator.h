#ifndef _OBIECTGENERATOR_H_
#define _OBIECTGENERATOR_H_

#include <random>
#include "ObiectDrawer.h"
#include "ObiectManager.h"

namespace MP
{
	class ObiectGenerator
	{
	private:

		std::mt19937 _random_number;

		void _generate_trees(ObiectManager& aObiectManager);

		void _generate_player(ObiectManager& aObiectManager);

	public:

		ObiectGenerator();

		void generateObiects(ObiectManager & aObiectManager);

	};
}
#endif