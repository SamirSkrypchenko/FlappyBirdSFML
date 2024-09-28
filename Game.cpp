#include "Game.h"
#include "Consts.h"


Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), windowTitle), 
			   background("img/background.png"),
			   bird("img/bird.png")
{
	// window.setFramerateLimit(FPS);
	window.setFramerateLimit(72);
}

void Game::run()
{
	sf::Time deltaTime;
	sf::Clock clock;

	while (window.isOpen() && !bird.checkCollisionWithGround())
	{
		deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event events;

	while (window.pollEvent(events))
	{
		switch (events.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
		}
	}

	bird.input();
}

void Game::update(sf::Time& deltaTime)
{
	bird.animation();
	bird.gravity(deltaTime);
	spawner.spawnObstacle();
	if (bird.state == Bird::FLY)
	{
		// двигаем все преп€тстви€
		for (int i = 0; i < spawner.MAX_COUNT_OF_OBSTACLES; i++)
		{
			spawner.obstacles[i]->move(deltaTime);
			// ≈сли птица пролетела какоето из преп€тствий засчитываем ей очко
			spawner.obstacles[i]->giveScoreTheBird(bird, counter);
			//
		}
		//
	}

	region.move(deltaTime);

	for (int i = 0; i < spawner.MAX_COUNT_OF_OBSTACLES; i++)
	{
		if (bird.checkColiisionWithObstacle(spawner.obstacles[i]))
		{
			window.close();
		}
	}
	bird.rotate(deltaTime);
}

void Game::render()
{
	window.clear();
	background.draw(window);
	// –исуем все преп€тстви€
	for (int i = 0; i < spawner.MAX_COUNT_OF_OBSTACLES; i++)
	{
		spawner.obstacles[i]->draw(window);
	}
	//
	region.draw(window);
	bird.draw(window);
	counter.draw(window);
	window.display();
}