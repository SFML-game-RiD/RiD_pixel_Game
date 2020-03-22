#include "MapAnimation.h"


void MP::MapAnimation::setColumnsRowSqrWidHei(int columns, int rows, int squareLength)
{
	_columns = columns;
	_rows = rows;
	_square_length = squareLength;
}

void MP::MapAnimation::setRectangleArray(Obiect& aObiect)
{
	int x = 0, y = 0;

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			y += _square_length;

			sf::IntRect tmp(x, y, _square_length, _square_length);

			_rectangle_array.push_back(tmp);
		}
		x += _square_length;
		y = 0;
	}
}
