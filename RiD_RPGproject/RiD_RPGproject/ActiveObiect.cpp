#include "ActiveObiect.h"
#include "Engine/ConfigurationLoader.h"

MP::ActiveObiect::ActiveObiect()
{
	_last_active = sf::milliseconds(0);
	_ready_time = sf::milliseconds(0);
	active_obj_sleep_time = sf::milliseconds(0);
	_obj_animation_sleep_time = sf::milliseconds(0);

	_block_length_copy=_block_length  = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");

	_distance_traveled = 0;
	_velocity = 0;
}

void MP::ActiveObiect::setLastActive(sf::Clock currentTime)
{
	_ready_time = _last_active = currentTime.getElapsedTime();
	_ready_time += active_obj_sleep_time;
}

sf::Time MP::ActiveObiect::getLastActiveTime()
{
	return _last_active;
}

sf::Time MP::ActiveObiect::getReadyTime()
{
	return _ready_time;
}

int MP::ActiveObiect::getBlockLenghtCopy()
{
	return _block_length_copy;
}

void MP::ActiveObiect::resetBlockLenghtCopy()
{
	_block_length_copy = _block_length;
	_distance_traveled = 0;
}

void MP::ActiveObiect::decreaseBlockLengthCopy()
{
	_block_length_copy-=_velocity;
	_distance_traveled += _velocity;
}

void MP::ActiveObiect::procedureMove()
{
}

int MP::ActiveObiect::getTraveledDistance()
{
	return _distance_traveled;
}

int MP::ActiveObiect::getVelocity()
{
	return _velocity;
}
