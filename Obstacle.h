#pragma once

#if !defined(OBSTACLE_H)
#define OBSTACLE_H

#include "Pipe.h"
#include "CounterScore.h"
#include "Bird.h"
#include <SFML/Graphics.hpp>


class Obstacle
{
	private:
		Pipe pipe1;
		Pipe pipe2;
	public:
		sf::Vector2f position;
		bool canGiveTheScore; // ���������� ��������� �������� �������� ���� ����� �� ��������� �����������, � ������ ���� ���������
	public:
			 Obstacle(); // ����������� �� ���������

		// ����� ������� ������ ����������� �� ������
		void draw(sf::RenderWindow& window); 

		// ����� ������� ������� �����������
		void move(const sf::Time& deltaTime);

		// ����� ������� ����� ������� �����������
		void setPosition(const sf::Vector2f& pos);

		// ����� ������� ����������� ����� ���� ����� ��� ��������� �����������
		void giveScoreTheBird(const Bird& bird, CounterScore& counter);
};

#endif