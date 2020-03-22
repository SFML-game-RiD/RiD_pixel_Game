#ifndef _MAPANIMATION_H_
#define _MAPANIMATION_H_
#include <vector>
#include "Engine/ConfigurationLoader.h"
#include "Obiect.h"

namespace MP
{
	class MapAnimation
	{
	private:

		int _columns;
		int _rows;
		int _square_length;

		std::vector<sf::IntRect> _rectangle_array;
	
	public:

	void setColumnsRowSqrWidHei(int columns, int rows, int squareLength);
		

		void setRectangleArray(Obiect &aObiect);
	};
}
#endif