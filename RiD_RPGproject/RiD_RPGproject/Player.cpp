#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "SpriteAnimation.h"
#include "Move.h"
#include "PathCreator.h"

void MP::Player::_player_animation_right(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(6, 8);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::_player_animation_left(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(3, 5);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::_player_animation_up(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(9, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::_player_animation_down(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(0, 2);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::_player_animation_idle(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time+ sf::milliseconds(1000))
	{
		aAnimation.setNextSprite(12, 14);
		setLastActiveAnimation(globalClock);
	}
}

MP::Player::Player(sf::Texture* texturePtr, sf::Texture* pathIconTexturePtr)
{	
	_path = nullptr;
	//saving path icon texture
	_a_path_icon_texture = pathIconTexturePtr;
	//Loading textures.
	aAnimation.loadObjectTextures(texturePtr,3,5,64);
	aAnimation.changeSprite(6);
	aAnimation.setScale(float(0.7), float(0.7));
	//Getting player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "SleepTime"));
	_obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "animationSleepTime"));
	
	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("player", "velocity");
	//Getting player coordinates.
	setObjectCoord(RiD::ConfigurationLoader::getIntData("player", "coordinateX"), RiD::ConfigurationLoader::getIntData("player", "coordinateY"));

	message[0] = "You have no mission.";
	message[2] = "Go and check notice board.";

}

void MP::Player::_player_animation(sf::Clock& globalClock, TaskManager &aMainTaskManager)
{
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_UP,false))
		_player_animation_up(globalClock);

	else if(aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_DOWN, false))
		_player_animation_down(globalClock);

	else if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_LEFT, false))
		_player_animation_left(globalClock);

	else if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT, false))
		_player_animation_right(globalClock);

	else
		_player_animation_idle(globalClock);
}

void MP::Player::_player_move(sf::Clock& aGameClock, TaskManager& aMainTaskManager)
{
	Move tmp;
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_UP, false))
		tmp.moveBlockUp(*this, aGameClock, aMainTaskManager);

	else if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_LEFT, false))
		tmp.moveBlockLeft(*this, aGameClock, aMainTaskManager);

	else if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_DOWN, false))
		tmp.moveBlockDown(*this, aGameClock, aMainTaskManager);

	else if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT, false))
		tmp.moveBlockRight(*this, aGameClock, aMainTaskManager);

	else
		this->resetBlockLenghtCopy();
}

void MP::Player::_player_automatic_move(Map& aMap, TaskManager& aTaskManager)
{
	if (aTaskManager.findTask(MP::TaskNode::taskType::TASK_EXECUTE_AUTO_MOVE, false))//execute auto move		
	{
		if (_path != nullptr and !aTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false))
		{

			MapElement* nextDestination = _path;//Takes new destination (new block).
			MapElement* tmp = aMap.findElementAddressSquareRange(getObjectCoord());//Return element where pawn stands.

			if (tmp->getLandTile().getObjectCoord().x == nextDestination->getLandTile().getObjectCoord().x
				and tmp->getLandTile().getObjectCoord().y + _block_length == nextDestination->getLandTile().getObjectCoord().y)//Goes down
			{
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_DOWN);
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
			}
			else if (tmp->getLandTile().getObjectCoord().x == nextDestination->getLandTile().getObjectCoord().x
				and tmp->getLandTile().getObjectCoord().y - _block_length == nextDestination->getLandTile().getObjectCoord().y)//Goes up
			{
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_UP);
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
			}
			else if (tmp->getLandTile().getObjectCoord().x + _block_length == nextDestination->getLandTile().getObjectCoord().x//Goes right
				and tmp->getLandTile().getObjectCoord().y == nextDestination->getLandTile().getObjectCoord().y)
			{
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT);
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
			}
			else if (tmp->getLandTile().getObjectCoord().x - _block_length == nextDestination->getLandTile().getObjectCoord().x//Goes left
				and tmp->getLandTile().getObjectCoord().y == nextDestination->getLandTile().getObjectCoord().y)
			{
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_LEFT);
				aTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
			}

			_set_path(_path->getNextElement());//Deleting usless element
			delete nextDestination;
		}
		else if (_path == nullptr and !aTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false))
		{
			aTaskManager.findTask(TaskNode::taskType::TASK_EXECUTE_AUTO_MOVE, true);
			aTaskManager.findTask(MP::TaskNode::taskType::TASK_AUTO_MOVE, true);
		}
	}
}

void MP::Player::_set_path(MapElement*& newPath)
{
	_path = newPath;
}

void MP::Player::_delete_player_path()
{
	if (_path == nullptr)
		return;
	else
	{
		MapElement* tmp = _path;

		while (_path != nullptr)
		{
			_path =_path->getNextElement();
			delete tmp;
			tmp = _path;
		}
	}
}

void MP::Player::_mark_path()
{

	MapElement* tmp = _path;

	while (tmp != nullptr)
	{
		std::unique_ptr<PathIcon> newPathIcon = std::make_unique<PathIcon>(_a_path_icon_texture, tmp->getLandTile().getObjectCoord());
		_a_path_icon.push_back(*newPathIcon);
		tmp = tmp->getNextElement();
	}

}

void MP::Player::_unmark_path()
{
	_a_path_icon.clear();
}

void MP::Player::goToPlace(Map& aGameMap, TaskManager& aMainTaskManger)
{
	MapElement *currentBlock = aGameMap.findElementAddressSquareRange(this->getObjectCoord());


	if (currentBlock->getPlace() != nullptr)
	{
		aMainTaskManger.setState(TaskManager::stateType::statePlacesMenu);
		_current_place = currentBlock->getPlace();
	}
}

std::shared_ptr<MP::Places>& MP::Player::getCurrentPlace()
{
	return _current_place;
}

std::string* MP::Player::getMessage()
{
	return message;
}

void MP::Player::update(SoundManager& aSoundManager, TaskManager& aMainTaskManager, sf::Clock& GameClock, MP::Map& aMap, sf::Vector2f mouseGameCoord)
{
	if (aMainTaskManager.getCurrentState() == MP::TaskManager::stateType::stateGame)
	{

		_player_animation(GameClock, aMainTaskManager);
		_player_move(GameClock, aMainTaskManager);
		_player_automatic_move(aMap, aMainTaskManager);
		_current_land = aMap.findElementAddressSquareRange(getObjectCoord());
		_mission_procedure(aMainTaskManager, aMap, aSoundManager);
		_song_procedure(GameClock, aSoundManager, aMainTaskManager);
		_procedure_player_auto_move(aMainTaskManager, GameClock, aMap, mouseGameCoord);
		_keyboard_handling(aMainTaskManager, aMap);




	}
}

void MP::Player::render(TaskManager& aMainTaskManager, sf::RenderWindow& mainWindow)
{
	if (aMainTaskManager.getCurrentState() == MP::TaskManager::stateType::stateGame)
	{
		mainWindow.draw(aAnimation.getObjectSprite());
		std::vector<PathIcon> tmpPathCopy = _a_path_icon;
		for (unsigned int i = 0; i < tmpPathCopy.size(); i++)
		{
			mainWindow.draw(tmpPathCopy[i].aAnimation.getObjectSprite());
		}
	}
}

void MP::Player::_procedure_player_auto_move(TaskManager& aMainTaskManager, sf::Clock& gameClock, MP::Map& aMap, sf::Vector2f& mouseGameCoord)
{
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_CREATE_PATH, true))//geting start and stop coordinates
	{
		MapElement* start = aMap.findElementAddressSquareRange(getObjectCoord());

		MapElement* stop = aMap.findElementAddressSquareRange(mouseGameCoord);

		if (stop->isWalkable())
		{
			if (start->getLandTile().getObjectCoord() != stop->getLandTile().getObjectCoord())	//creating path
			{
				checkingVector = stop->getLandTile().getObjectCoord();


				MP::PathCreator  tmp(aMap);

				_set_path(tmp.findPath(start->getLandTile().getObjectCoord(), stop->getLandTile().getObjectCoord()));

				_mark_path();

				aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_WAIT_FOR_LEFT_DOUBLE_CLICK); //computer waiting for player reply
			}
		}
	}
	else if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_LEFT_DOUBLE_CLICK, true))//starts procedure auto move if player clicked second time
	{
		MapElement* checkingElement = aMap.findElementAddressSquareRange(mouseGameCoord);

		if (checkingElement->getLandTile().getObjectCoord() == checkingVector and checkingElement != aMap.findElementAddressSquareRange(getObjectCoord())) //continue auto move
		{
			_unmark_path();
			aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_EXECUTE_AUTO_MOVE);
		}
		else //break auto move
		{
			_unmark_path();
			_delete_player_path();
			aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_AUTO_MOVE, true);
		}
	}
	else if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_BREAK_AUTO_MOVE, true))//breaks auto move
	{
		_delete_player_path();
		aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_AUTO_MOVE, true);
	}

}

void MP::Player::_song_procedure(sf::Clock& gameClock, MP::SoundManager& aSoundManager, TaskManager& aMainTaskManager)
{
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE, false))
	{
		if (!_sound_player.isPlaying())
		{
			_sound_player.playSound(aSoundManager.getSound("pawnSound"));
			_whinney_once = true;
			objectTimer.setTimer(gameClock, sf::seconds(float(1.3)));
		}
	}
	else
		if (_whinney_once == true)
		{
			_sound_player.stopSound();
			if (objectTimer.timeControl(gameClock, sf::seconds(float(1.3))))
			{
				_sound_player.playSound(aSoundManager.getSound("horseWhinney"));
				_whinney_once = false;
			}
		}
}

void MP::Player::_mission_procedure(TaskManager& aMainTaskManager, Map& gameMap, SoundManager& aSoundManager)
{
	if (aMainTaskManager.findTask(TaskNode::taskType::taskMission, true))
	{
		if (_current_mision == nullptr)
		{
			_current_mision = _a_mission_creator.getMission(_current_place->getPlaceMark());
			_destination_place = gameMap.getRandomPlace(_current_mision->getDestination());
			_destination_place->markPlace();
			_employer_place = _current_place;

			for (int i = 0; i < 12; i++)
				message[i] = _current_mision->getStartMessage()[i];


			aMainTaskManager.addTask(TaskNode::taskType::taskMissionGoToDestination);
			_current_mision->missionSoundPlayer.playSound(aSoundManager.getSound("missionNextState"));
		}
	}
	else if (aMainTaskManager.findTask(TaskNode::taskType::taskMissionGoToDestination, false))
	{

		//if(_current_land!=nullptr)
		if (_current_land->getPlace() == _destination_place)
		{

			aMainTaskManager.findTask(TaskNode::taskType::taskMissionGoToDestination, true);

			if (_current_mision->getAction() == "nothing")
				aMainTaskManager.addTask(TaskNode::taskType::taskMissionGetReward);
			else if (_current_mision->getAction() == "return")
			{
				_current_mision->missionSoundPlayer.playSound(aSoundManager.getSound("missionNextState"));
				aMainTaskManager.addTask(TaskNode::taskType::taskMissionReturn);
				_destination_place->unmarkPlace();
				_employer_place->markPlace();
			}



			for (int i = 0; i < 12; i++)
				message[i] = _current_mision->getDestinationMessage()[i];


		}
	}
	else  if (aMainTaskManager.findTask(TaskNode::taskType::taskMissionGetReward, true))
	{
		_current_mision->missionSoundPlayer.playSound(aSoundManager.getSound("missionCompleted"));
		for (int i = 0; i < 12; i++)
			message[i] = _current_mision->getEndMessage()[i];

		aItemsManager.getGold()->setItemAmount(aItemsManager.getGold()->getItemAmount() + _current_mision->getAwardAmount("gold"));
		aItemsManager.getWood()->setItemAmount(aItemsManager.getWood()->getItemAmount() + _current_mision->getAwardAmount("wood"));
		aItemsManager.getIron()->setItemAmount(aItemsManager.getIron()->getItemAmount() + _current_mision->getAwardAmount("iron"));
		aItemsManager.getFood()->setItemAmount(aItemsManager.getFood()->getItemAmount() + _current_mision->getAwardAmount("food"));
		aItemsManager.getSpearman()->setItemAmount(aItemsManager.getSpearman()->getItemAmount() + _current_mision->getAwardAmount("spearman"));
		aItemsManager.getSwordsman()->setItemAmount(aItemsManager.getSwordsman()->getItemAmount() + _current_mision->getAwardAmount("swordsman"));
		aItemsManager.getArcher()->setItemAmount(aItemsManager.getArcher()->getItemAmount() + _current_mision->getAwardAmount("archer"));

		_current_mision = nullptr;
		_destination_place->unmarkPlace();
		_employer_place->unmarkPlace();
	}
	else if (aMainTaskManager.findTask(TaskNode::taskType::taskMissionReturn, false))
	{
		if (_current_land->getPlace() == _employer_place)
		{
			aMainTaskManager.addTask(TaskNode::taskType::taskMissionGetReward);
			aMainTaskManager.findTask(TaskNode::taskType::taskMissionReturn, true);
		}
	}
}






void MP::Player::_keyboard_handling(TaskManager& aMainTaskManager, Map& gameMap)
{
	Move tmp;
	if (aMainTaskManager.findTask(TaskNode::taskType::W_PRESSED, false))
		tmp.tryToMoveUp(*this,gameMap, aMainTaskManager);
	else if (aMainTaskManager.findTask(TaskNode::taskType::A_PRESSED, false))
		tmp.tryToMoveLeft(*this, gameMap, aMainTaskManager);
	else if (aMainTaskManager.findTask(TaskNode::taskType::S_PRESSED, false))
		tmp.tryToMoveDown(*this, gameMap, aMainTaskManager);
	else if (aMainTaskManager.findTask(TaskNode::taskType::D_PRESSED, false))
		tmp.tryToMoveRight(*this, gameMap, aMainTaskManager);

	else if (aMainTaskManager.findTask(TaskNode::taskType::E_PRESSED, false))
		goToPlace(gameMap, aMainTaskManager);
}
