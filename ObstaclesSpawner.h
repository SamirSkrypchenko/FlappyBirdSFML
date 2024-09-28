#pragma once

#if !defined(OBSTACLESSPAWNER_H)
#define OBSTACLESSPAWNER_H

#include "Obstacle.h"


class ObstaclesSpawner
{	
	public:
		static const unsigned int MAX_COUNT_OF_OBSTACLES = 4;
		Obstacle*	     obstacles[MAX_COUNT_OF_OBSTACLES];

	public:
						 ObstaclesSpawner(); // Конструктор по умолчанию

		// Хоть здесь и написано спавнер, на самом деле этот метод 
		// перемещает самое левое препятствие на место перед самым правым препятствием
		// если самое левое препятствие выходит за экран
		// Создавая иллюзию того что препятствия спавнятся.
		// Принцип этого метода похож на перемещение части земли
		// которая находится в самом левом краю участка 
		// на место в самом правом краю участка
		void			 spawnObstacle();

						~ObstaclesSpawner(); // Деструктор
};

#endif