#ifndef _OBIECTGENERATOR_H_
#define _OBIECTGENERATOR_H_

#include <random>
#include "ObiectDrawer.h"
#include "ObiectManager.h"
#include "Engine/AssetManager.h"

namespace MP
{
	class ObiectGenerator
	{
	private:

		RiD::AssetManager _a_asset_manager;

		std::mt19937 _random_number;

		void _generate_trees(ObiectManager& aObiectManager);

		void _generate_player(ObiectManager& aObiectManager);

		void _generate_map(ObiectManager& aObiectManager);

		void _generate_computer_player(ObiectManager& aObiectManager);

		void _generate_cursor(ObiectManager& aObiectManager);

	public:

		ObiectGenerator();

		void generateObiects(ObiectManager & aObiectManager);

	};
}
#endif