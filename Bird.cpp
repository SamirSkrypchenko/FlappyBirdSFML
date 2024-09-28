#include "Bird.h"
#include "Consts.h"
#include "ObstaclesSpawner.h"
#include <string.h>
#include <cmath>


Bird::Bird(const std::string& pathTexture) : position(sf::Vector2f(WIDTH / 2 - WIDTH / 4, HEIGHT / 2)),
											 speedY(0.f),
										     state(STAY),
											 canFlight(true)
{
	loadSprite(pathTexture);
	sprite.setTextureRect(sf::IntRect(0, 0, 276 / 3, 64));
	sprite.setOrigin(276 / 6, 32);
	sprite.setPosition(position);
}


int Bird::loadSprite(const std::string& pathTexture)
{
	if (!texture.loadFromFile(pathTexture))
		return EXIT_FAILURE;

	sprite.setTexture(texture);
}


void Bird::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}


void Bird::animation()
{
	static int frame = 0; // Какой сейчас кадр по счету (кадра всего 3 и счёт начинается с 0)
	static sf::Clock clock; // Время прошедшее с последнего изменения кадра

	if (clock.getElapsedTime().asSeconds() >= TIME_BETWEEN_FRAMES)
	{
		frame++;
		sprite.setTextureRect(sf::IntRect(276 / 3 * frame, 0, 276 / 3, 64));
		clock.restart();
	}
		
	if (frame >= 2)
		frame = -1;
}


void Bird::gravity(const sf::Time& dt)
{
	if (state == FLY)
	{
		if (speedY <= SPEEDY_MAX)
			speedY += GRAVITY * dt.asSeconds();
		position.y += speedY * dt.asSeconds();

		sprite.setPosition(position);
	}
}


bool Bird::checkCollisionWithGround() const
{
	if (position.y > HEIGHT - HEIGHT_OF_GROUND - 32)
		return true;

	return false;
}


bool Bird::checkColiisionWithObstacle(const Obstacle* obstacle) const
{
	float dx = (position.x <= obstacle->position.x) ? (obstacle->position.x - position.x - REC_COLL_SHAPE_OF_THE_BIRD.x / 2) 
													: (position.x - obstacle->position.x - REC_COLL_SHAPE_OF_THE_BIRD.x / 2);
	float dy = (position.y <= obstacle->position.y) ? (obstacle->position.y - position.y + REC_COLL_SHAPE_OF_THE_BIRD.y / 2)
											        : (position.y - obstacle->position.y + REC_COLL_SHAPE_OF_THE_BIRD.y / 2);

	if (dx < LENGTH_OF_PIPE / 2)
		if (dy > HEIGHT / 3 - HEIGHT / 6)
			return true;

	return false;
}


void Bird::flight()
{
	speedY = -950.f;
}


void Bird::rotate(const sf::Time& dt)
{
	sprite.setRotation(atan(speedY / 950) * 180 / PI);
}


void Bird::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (canFlight)
		{
			if (state == FLY)
				flight();
			else if (state == STAY)
			{
				state = FLY;
				flight();
			}
			canFlight = false;
		}
	}
	else
		canFlight = true;
}
