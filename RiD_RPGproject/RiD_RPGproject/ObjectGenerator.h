#pragma once

#include <random>
#include "SoundManager.h"
#include "ObjectDrawer.h"
#include "ObjectManager.h"
#include "Engine/AssetManager.h"

namespace MP
{
	class ObjectGenerator
	{
	private:

		RiD::AssetManager _a_asset_manager;

		MP::SoundManager _a_sound_manager;

		std::mt19937 _random_number;

		void _generate_trees(ObjectManager& aObiectManager);

		void _generate_player(ObjectManager& aObiectManager);

		void _generate_map(ObjectManager& aObiectManager);

		void _generate_computer_player(ObjectManager& aObiectManager);

		void _generate_cursor(ObjectManager& aObiectManager);

		void _generate_gui(ObjectManager& aObiectManager);

		void _generate_items_for_places(ItemsManager& itemsFromPlaces, ItemsManager& itemsForTrade, int multiplier, int tradeMultiplier,char placesMark);

	public:

		ObjectGenerator();

		void generateObiects(ObjectManager & aObiectManager);

	};
}