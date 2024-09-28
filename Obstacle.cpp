#include "Obstacle.h"
#include "Consts.h"
#include "CounterScore.h"


Obstacle::Obstacle() : canGiveTheScore(true)
{
	pipe2.rotate(180);
}

void Obstacle::draw(sf::RenderWindow& window)
{
	pipe1.draw(window);
	pipe2.draw(window);
}

void Obstacle::move(const sf::Time& deltaTime)
{
	sf::Time dtTemp = deltaTime;
	pipe1.move(dtTemp);
	pipe2.move(dtTemp);
	position.x -= SPEED_ELEMENTS * dtTemp.asSeconds();
}

void Obstacle::setPosition(const sf::Vector2f& pos)
{
	position = pos;
	pipe1.position = pos;
	pipe2.position = pos;
	pipe1.position.x -= LENGTH_OF_PIPE / 2;
	pipe2.position.x += LENGTH_OF_PIPE / 2;
	pipe1.position.y += HEIGHT / 3 - HEIGHT / 6;
	pipe2.position.y -= HEIGHT / 3 - HEIGHT / 6;
}

void Obstacle::giveScoreTheBird(const Bird& bird, CounterScore& counter)
{
	if (canGiveTheScore)
	{
		if (bird.position.x - REC_COLL_SHAPE_OF_THE_BIRD.x / 2 >= position.x)
		{
			++counter;
			counter.setText(counter.getScore());
			canGiveTheScore = false;
		}
	}
}