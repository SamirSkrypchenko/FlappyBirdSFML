#include "ObstaclesSpawner.h"
#include "Consts.h"
#include "random"
#include "ctime"


ObstaclesSpawner::ObstaclesSpawner()
{
	
	for (int i = 0; i < MAX_COUNT_OF_OBSTACLES; i++)
	{	
		srand(time(NULL) + i);
		float randPosY = (rand() % 20 + 2) * (HEIGHT - HEIGHT_OF_GROUND - HEIGHT / 6) / 20;
		obstacles[i] = new Obstacle;
		obstacles[i]->setPosition(sf::Vector2f(WIDTH + LENGTH_OF_PIPE / 2 + i * DISTANCE_BETWEEN_OBSTACLES, randPosY));
	}

	srand(time(NULL));
}

void ObstaclesSpawner::spawnObstacle()
{
	static int index1 = 0; // Индекс самого левого препятствия
	static int index2 = MAX_COUNT_OF_OBSTACLES - 1; // Индекс самого правого препятствия

	if (obstacles[index1]->position.x < -LENGTH_OF_PIPE) // Если препятствие под индексом index1 находится за экраном
	{
		// перемещаем препятствие под индексом index1 на место препятствия под индексом index2, 
		// делаем между ними шаг DISTANCE_BETWEEN_OBSTACLES
		// и задаём препятствию под индексом index1 рандомную позицию по Y
		obstacles[index1]->setPosition(sf::Vector2f(obstacles[index2]->position.x + DISTANCE_BETWEEN_OBSTACLES, 
									  (rand() % 20 + 2) * (HEIGHT - HEIGHT_OF_GROUND - HEIGHT / 6) / 20));
		obstacles[index1]->canGiveTheScore = true; // После повторного прохождения препятствия под индексом index1 птица снова сможет получить очко
	}

	index2 = index1++; // присваиваем index2 значение index1 так как препятствие 
					   // под индексом index1 теперь является самым правым.
					   // А затем инкрементируем index1

	if (index1 >= MAX_COUNT_OF_OBSTACLES) // если index1 >= MAX_COUNT_OF_OBSTACLES то это значит что
		index1 = 0;						  // самое правое препятствие снова имеет индекс равный 0
}

ObstaclesSpawner::~ObstaclesSpawner()
{
	for (int i = 0; i < MAX_COUNT_OF_OBSTACLES; i++)
	{
		delete obstacles[i];
	}
}

