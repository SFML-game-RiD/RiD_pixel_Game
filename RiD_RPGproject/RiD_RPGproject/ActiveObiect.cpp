#include "ActiveObiect.h"
#include "Engine/ConfigurationLoader.h"

MP::ActiveObiect::ActiveObiect()
{
	_last_active = sf::milliseconds(0);
	_block_length = _block_length_copy = RiD::ConfigurationLoader::getIntData("video settings", "blockLength");
	_is_moving = false;
}

void MP::ActiveObiect::setLastActive(sf::Clock currentTime)
{
	_last_active = currentTime.getElapsedTime();
}

sf::Time MP::ActiveObiect::getLastActiveTime()
{
	return _last_active;
}

int MP::ActiveObiect::getBlockLenghtCopy()
{
	return _block_length_copy;
}

void MP::ActiveObiect::resetBlockLenghtCopy()
{
	_block_length_copy = _block_length;
}

void MP::ActiveObiect::decreaseBlockLengthCopy()
{
	_block_length_copy--;
}

void MP::ActiveObiect::procedureMove()
{
}

void MP::ActiveObiect::setIsMoving(bool isTrue)
{
	_is_moving = isTrue;
}

bool MP::ActiveObiect::getIsMoving()
{
	return _is_moving;
}
