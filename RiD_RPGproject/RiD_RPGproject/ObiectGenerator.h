#ifndef OBIECTGENERATOR_H
#define OBIECTGENERATOR_H

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

		void _generate_gui(ObiectManager& aObiectManager);

		void _generate_items_for_places(ItemsManager &itemsFromPlaces, int modulo);

	public:

		ObiectGenerator();

		void generateObiects(ObiectManager & aObiectManager);

	};
}
#endif