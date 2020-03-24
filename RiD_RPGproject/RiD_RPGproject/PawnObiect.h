#ifndef _PAWNOBIECT_H_
#define _PAWNOBIECT_H_

#include "SFML/Graphics.hpp"
#include "ActiveObiect.h"
#include <vector>

namespace MP 
{
	class PawnObiect:public ActiveObiect
	{
	private:

		enum direction 
		{
			directionUp,
			directionDown,
			directionLeft,
			directionRight,
			directionNone
		};

		direction _current_direction;
		int _past_pixels;
		int _current_past_pixels;

	/*	std::vector<sf::IntRect> directionUpArray;
		std::vector<sf::IntRect> directionDownArray;
		std::vector<sf::IntRect> directionLeftArray;
		std::vector<sf::IntRect> directionRightArray;*/

	public:
		
		PawnObiect();

		void pawnAnimation();

		void pawnAnimationRight();
		
		void setNextSprite(int from, int to);
	};
}
#endif
