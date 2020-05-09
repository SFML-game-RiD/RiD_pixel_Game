#pragma once
#include <SFML/Graphics.hpp>

namespace MP
{
	class SmallMapPart
	{
	private:

		sf::Vector2f coord;

		//std::shared_ptr<MP::SmallMapPart> _up_element,  _down_element, _left_element,  _right_element;

		std::shared_ptr<MP::SmallMapPart> _next_element;

		bool _walkable;

	public:

		SmallMapPart(sf::Vector2f smallMapCoord, bool isWalkable);

		sf::Vector2f getSmallPartCoord();

		void setNextPtr(std::shared_ptr<MP::SmallMapPart> aMapElement);

		bool isWalkable();
		//void setUpPtr(std::shared_ptr<MP::SmallMapPart> aMapElement);

		//void setDownPtr(std::shared_ptr<MP::SmallMapPart> aMapElement);

		//void setLeftPtr(std::shared_ptr<MP::SmallMapPart> aMapElement);

		//void setRightPtr(std::shared_ptr<MP::SmallMapPart> aMapElement);



		std::shared_ptr<MP::SmallMapPart> getNextElement();

		//std::shared_ptr<MP::SmallMapPart> getUpPtrCopy();

		//std::shared_ptr<MP::SmallMapPart> getDownPtrCopy();

		//std::shared_ptr<MP::SmallMapPart> getLeftPtrCopy();

		//std::shared_ptr<MP::SmallMapPart> getRightPtrCopy();
	};

}