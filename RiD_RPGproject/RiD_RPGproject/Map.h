#ifndef _MAP_H_
#define _MAP_H_
#include "MapElement.h"

namespace MP
{

	class Map
	{
	private:

		int _block_length;

		MapElement * _map_element_list;

		void _delete_map(MapElement *&head);

		void _load_map();

		void _add_map_element(MapElement*& head, MapElement*& newElement);

		void _create_web();

	public:

		Map();

		~Map();

		MapElement*& getMapElementList();

		MapElement* findElementAddress(/*std::pair<int, int> coordinates*/sf::Vector2f coordinates, MapElement*& mapElementHead);
	};
}
#endif // !Map