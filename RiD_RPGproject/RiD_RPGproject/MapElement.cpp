#include "Engine/ConfigurationLoader.h"
#include "MapElement.h"
#include "Village.h"
#include "Town.h"
#include "Castle.h"

void MP::MapElement::_create_village(sf::Texture* texturePtr, sf::Vector2f coord)
{
	_a_place = std::make_shared<MP::Village>(texturePtr,this->getLandTile().getObiectCoord());
}

void MP::MapElement::_create_town(sf::Texture* texturePtr, sf::Vector2f coord)
{
	_a_place = std::make_shared<MP::Town>(texturePtr,this->getLandTile().getObiectCoord());
}

void MP::MapElement::_create_castle(sf::Texture* texturePtr, sf::Vector2f coord)
{
	_a_place = std::make_shared<MP::Castle>(texturePtr,this->getLandTile().getObiectCoord());
}

MP::Land & MP::MapElement::getLandTile()
{
	return *std::dynamic_pointer_cast<Land>(_land_tile);;
}

std::shared_ptr<MP::Places>& MP::MapElement::getPlace()
{
	return _a_place;
}


MP::MapElement::MapElement(RiD::AssetManager& aAssetManager, int cordX, int cordY, char mark, int &walkableCount)
{
	_up_element = nullptr;
	_down_element = nullptr;
	_left_element = nullptr;
	_right_element = nullptr;

	_next_element = nullptr;

	_mark = mark;

	if (mark == RiD::ConfigurationLoader::getStringData("game settings", "treeWallMark")[0])
		_walkable = false;
	else
	{
		walkableCount++;
		_walkable = true;
	}
	if (mark != '~')
	{
		_land_tile = std::make_shared<MP::Land>(&aAssetManager.getTexture("land"), cordX, cordY);

		//Creating places.

		if (mark == RiD::ConfigurationLoader::getStringData("village", "mark")[0])
			_create_village(&aAssetManager.getTexture("village"), _land_tile->getObiectCoord());
		else if (mark == RiD::ConfigurationLoader::getStringData("castle", "mark")[0])
			_create_castle(&aAssetManager.getTexture("castle"), _land_tile->getObiectCoord());
		else if (mark == RiD::ConfigurationLoader::getStringData("town", "mark")[0])
			_create_town(&aAssetManager.getTexture("town"), _land_tile->getObiectCoord());
		else
			_a_place = nullptr;
	}
	else
	{
		_land_tile = std::make_shared<MP::Land>(cordX, cordY);
	}
}

MP::MapElement*& MP::MapElement::getNextElement()
{
	return _next_element;
}

MP::MapElement*& MP::MapElement::getUpPtr()
{
	return _up_element;
}

MP::MapElement*& MP::MapElement::getDownPtr()
{
	return _down_element;
}

MP::MapElement*& MP::MapElement::getLeftPtr()
{
	return _left_element;
}

MP::MapElement*& MP::MapElement::getRightPtr()
{
	return _right_element;
}

char MP::MapElement::getMark()
{
	return _mark;
}

void MP::MapElement::setNextPtr(MapElement* aMapElement)
{
	_next_element = aMapElement;
}

void MP::MapElement::setUpPtr(MapElement* aMapElement)
{
	_up_element = aMapElement;
}

void MP::MapElement::setDownPtr(MapElement* aMapElement)
{
	_down_element = aMapElement;
}

void MP::MapElement::setLeftPtr(MapElement* aMapElement)
{
	_left_element = aMapElement;
}

void MP::MapElement::setRightPtr(MapElement* aMapElement)
{
	_right_element = aMapElement;
}

bool MP::MapElement::isWalkable()
{
	return _walkable;
}

MP::MapElement* MP::MapElement::returnAddress()
{
	return this;
}
