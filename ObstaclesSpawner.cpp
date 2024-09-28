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
	static int index1 = 0; // ������ ������ ������ �����������
	static int index2 = MAX_COUNT_OF_OBSTACLES - 1; // ������ ������ ������� �����������

	if (obstacles[index1]->position.x < -LENGTH_OF_PIPE) // ���� ����������� ��� �������� index1 ��������� �� �������
	{
		// ���������� ����������� ��� �������� index1 �� ����� ����������� ��� �������� index2, 
		// ������ ����� ���� ��� DISTANCE_BETWEEN_OBSTACLES
		// � ����� ����������� ��� �������� index1 ��������� ������� �� Y
		obstacles[index1]->setPosition(sf::Vector2f(obstacles[index2]->position.x + DISTANCE_BETWEEN_OBSTACLES, 
									  (rand() % 20 + 2) * (HEIGHT - HEIGHT_OF_GROUND - HEIGHT / 6) / 20));
		obstacles[index1]->canGiveTheScore = true; // ����� ���������� ����������� ����������� ��� �������� index1 ����� ����� ������ �������� ����
	}

	index2 = index1++; // ����������� index2 �������� index1 ��� ��� ����������� 
					   // ��� �������� index1 ������ �������� ����� ������.
					   // � ����� �������������� index1

	if (index1 >= MAX_COUNT_OF_OBSTACLES) // ���� index1 >= MAX_COUNT_OF_OBSTACLES �� ��� ������ ���
		index1 = 0;						  // ����� ������ ����������� ����� ����� ������ ������ 0
}

ObstaclesSpawner::~ObstaclesSpawner()
{
	for (int i = 0; i < MAX_COUNT_OF_OBSTACLES; i++)
	{
		delete obstacles[i];
	}
}

