#ifndef _MAP_H_
#define _MAP_H_
#include "MapElement.h"

namespace MP
{

	class Map
	{
	private:

		MapElement * _map_element_list;

		void _delete_map(MapElement *&head);

		void _load_map();

		void _add_map_element(MapElement*& head, MapElement*& newElement);

	public:

		Map();

		~Map();

		MapElement*& getMapElementList();
	};
}
#endif // !Map