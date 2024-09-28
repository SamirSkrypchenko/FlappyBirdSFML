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
						 ObstaclesSpawner(); // ����������� �� ���������

		// ���� ����� � �������� �������, �� ����� ���� ���� ����� 
		// ���������� ����� ����� ����������� �� ����� ����� ����� ������ ������������
		// ���� ����� ����� ����������� ������� �� �����
		// �������� ������� ���� ��� ����������� ���������.
		// ������� ����� ������ ����� �� ����������� ����� �����
		// ������� ��������� � ����� ����� ���� ������� 
		// �� ����� � ����� ������ ���� �������
		void			 spawnObstacle();

						~ObstaclesSpawner(); // ����������
};

#endif