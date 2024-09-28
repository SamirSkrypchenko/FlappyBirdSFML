#pragma once

#if !defined(GAME_H)
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Bird.h"
#include "Region.h"
#include "ObstaclesSpawner.h"
#include "CounterScore.h"


class Game
{
	private:
		sf::Texture	     textureBackground;
		sf::RenderWindow window;
		Background		 background;
		Bird			 bird;
		Region			 region;
		CounterScore	 counter;
	public:
		ObstaclesSpawner spawner;

	private:
		// Ётот метод считывает событи€ (такие как нажатие клавиши, или изменени размера окна)
		void		     processEvents();

		// Ётот метод обновл€ет логику игры.
		//  ѕараметр deltaTime это отрезок времени между двум€ соседними кадрами
		void			 update(sf::Time& deltaTime);

		// Ётот метод рисует объекты внутри окна
		void			 render();
	public:
					     Game(); //  онструктор

		// ћетод дл€ запуска игры
		void		     run();
};	

#endif