#pragma once

#include "SFML/Graphics.hpp"

namespace RTB
{
	class OrientedHitbox // Used in the BoundingBoxTest
	{
	public:
		OrientedHitbox(const sf::RectangleShape& Object, const int width, const int height); // Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite

		sf::Vector2f Points[4];

		void ProjectOntoAxis(const sf::Vector2f& Axis, float& Min, float& Max); // Project all four points of the OBB onto the given axis and return the dotproducts of the two outermost points
	};
}