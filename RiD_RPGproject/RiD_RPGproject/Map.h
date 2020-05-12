#ifndef MAP_H
#define MAP_H
#include <random>
#include "MapElement.h"

namespace MP
{

	class Map
	{
	private:

		sf::Vector2i _last_element_coord;

		std::mt19937 _random_value;

		int _block_length;

		float _block_length_neg_one;

		std::vector<std::vector<MapElement*>> _map_array;

		std::vector<std::shared_ptr<Places>> _places_list;

		void _delete_map();

	public:

		Map();

		~Map();

		MapElement* findElementAddress(sf::Vector2f coordinates);

		MapElement* findElementAddress(float x,float y);

		MapElement* findElementAddressSquareRange(sf::Vector2f coordinates);

		void copyMapArrayAndBlockSize(std::vector<std::vector<MapElement*>> &aMapElementList,int blockSize);

		MapElement* returnRandomWalkableElement();

		void  setLastElementCoord(sf::Vector2f aVector);

		std::vector<std::vector<MapElement*>>& getMapArray();
		
		int getBlockSize();

		std::shared_ptr<Places> getRandomPlace(char mark);
		
		void createPlacesList();
	};
}
#endif // !Map