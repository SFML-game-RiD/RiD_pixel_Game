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

	public:

		Map();

		~Map();

		void createWeb();

		void addMapElement(MapElement*& head, MapElement*& newElement);

		MapElement*& getMapElementList();

		MapElement* findElementAddress(sf::Vector2f coordinates, MapElement*& mapElementHead);

		MapElement* findElementAddressSquareRange(sf::Vector2f coordinates, MapElement*& mapElementHead);


	};
}
#endif // !Map