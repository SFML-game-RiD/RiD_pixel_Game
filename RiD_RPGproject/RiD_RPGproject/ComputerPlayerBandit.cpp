#include "ComputerPlayerBandit.h"
#include "Move.h"

MP::ComputerPlayerBandit::ComputerPlayerBandit(sf::Texture* texturePtr)
{

	_path = nullptr;
	_is_enemys_check = false;
	//Loading textures.
	aAnimation.loadObjectTextures(texturePtr, 4, 4, 64);
	aAnimation.changeSprite(6);
	aAnimation.setScale(float(0.8), float(0.8));

	//Getting computer player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "SleepTime"));
	_obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "animationSleepTime"));

	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("computer player", "velocity");

	//Getting player coordinates.
	setObjectCoord(RiD::ConfigurationLoader::getIntData("computer player", "coordinateX"), RiD::ConfigurationLoader::getIntData("computer player", "coordinateY"));

	//Loading radius
	_radius = RiD::ConfigurationLoader::getIntData("computer player", "radius");
}

void MP::ComputerPlayerBandit::_chose_destination(Map &aMap)
{
	MP::PathCreator tmp(aMap);
	sf::Vector2f destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObjectCoord();
	MapElement* startingElement = aMap.findElementAddressSquareRange(getObjectCoord());

	while(destinationCoord == startingElement->getLandTile().getObjectCoord())
		destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObjectCoord();

	//Chose random destination and calculate path.
	
	_path =  tmp.findPath(startingElement->getLandTile().getObjectCoord(),destinationCoord);
}

void MP::ComputerPlayerBandit::_delete_path()
{
	if (_path == nullptr)
		return;
	else
	{
		while (_path != nullptr)
		{
			MapElement* tmp = _path;

			_path = _path->getNextElement();
			delete tmp;
		}
	}
}

bool MP::ComputerPlayerBandit::_check_enemy(std::shared_ptr<Player>& aPlayer)
{
	if (!_is_enemys_check and _current_land!=nullptr)
	{
		sf::Vector2f radiusCoord;
		sf::Vector2f player = aPlayer->getObjectCoord();
		radiusCoord.x = getObjectCoord().x - _radius;
		radiusCoord.y = getObjectCoord().y - _radius;
		
		_is_enemys_check = false;

		if (radiusCoord.x + 2 * _radius > player.x and radiusCoord.x < player.x)
			if (radiusCoord.y + 2 * _radius > player.y and radiusCoord.y < player.y)
			{
				_is_enemys_check = true;
				return true;
			}
	}
	return false;
}

void MP::ComputerPlayerBandit::_song_procedure(MP::SoundManager& aSoundManager)
{
	if (!_sound_player.isPlaying())
		if(_is_enemys_check)
		if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false) or
			aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoUp, false) or
			aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false) or
			aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
			_sound_player.playSound(aSoundManager.getSound("pawnSound"));
}

void MP::ComputerPlayerBandit::_get_next_task(Map& aMap)
{
	if (aPawnObjectTaskManager.isTaskListEmpty())
	{
		if (_path == nullptr)//Sets new destination.
		_chose_destination(aMap);

		MapElement* nextDestination = _path;//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObjectCoord());//Return element where computer player stands.

		_current_land = tmp;
		_is_enemys_check = false;

		if (tmp->getLandTile().getObjectCoord().x == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y + _block_length == nextDestination->getLandTile().getObjectCoord().y)//Goes down
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::taskGoDown);

		else if (tmp->getLandTile().getObjectCoord().x == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y - _block_length == nextDestination->getLandTile().getObjectCoord().y)//Goes up
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::taskGoUp);

		else if (tmp->getLandTile().getObjectCoord().x + _block_length == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y == nextDestination->getLandTile().getObjectCoord().y)
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::taskGoRight);

		else if (tmp->getLandTile().getObjectCoord().x - _block_length == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y == nextDestination->getLandTile().getObjectCoord().y)
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::taskGoLeft);

		_path = _path->getNextElement();//Deleting usless element
		delete nextDestination;	
	}
}

void MP::ComputerPlayerBandit::_computer_player_move(sf::Clock& globalClock)
{
	MP::Move tmp;

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoUp, false))
		tmp.moveBlockUp(*this, globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false))
		tmp.moveBlockLeft(*this, globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false))
		tmp.moveBlockDown(*this, globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
		tmp.moveBlockRight(*this, globalClock);

	if (aPawnObjectTaskManager.isTaskListEmpty())
		this->resetBlockLenghtCopy();
}

MP::ComputerPlayerBandit::~ComputerPlayerBandit()
{
	_delete_path();
}

void MP::ComputerPlayerBandit::_computer_player_animation(sf::Clock& globalClock)
{
	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoUp, false))
		_computer_player_animation_up(globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false))
		_computer_player_animation_down(globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false))
		_computer_player_animation_left(globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
		_computer_player_animation_right(globalClock);
}

void MP::ComputerPlayerBandit::_computer_player_animation_right(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(8, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_left(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(4, 7);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_up(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(12, 15);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_down(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(0, 3);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::update(SoundManager& aSoundManager, Map& aMap, sf::Clock& gameClock, std::shared_ptr<Player>& aPlayer)
{
	if (_check_enemy(aPlayer))
	{
		std::cout << " WYKRYLEM GRACZA \n" << std::endl;
	
	}	
	_song_procedure(aSoundManager);
	_get_next_task(aMap);
	_computer_player_animation(gameClock);
	_computer_player_move(gameClock);
}

void MP::ComputerPlayerBandit::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
}