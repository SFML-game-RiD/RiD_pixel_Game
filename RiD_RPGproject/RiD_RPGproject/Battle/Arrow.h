#pragma once

#include "SFML/Graphics.hpp"
#include "ArrowHitbox.h"

namespace RTB
{
	class Arrow
	{
	private:
		ArrowHitbox *_hitbox = nullptr;
		sf::Sprite *_sprite = nullptr;
		sf::Sprite* _character;
		sf::Time _fly_time, _start_time;
		enum directions { up, left, down, right };
		bool _is_flying, _change_direction;
		short _direction;
		float _speed = 10.f;
	public:
		Arrow(sf::Sprite*& character, sf::Texture& texture);
		~Arrow();

		void update();

		void render(sf::RenderTarget& window);

		void fly(sf::Time time, sf::RenderTarget& window, short direction);

		bool checkIntersection(const sf::FloatRect& rectangle);

		bool isFlying();

		sf::Vector2f getPosition();
	};
}