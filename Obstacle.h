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
		bool canGiveTheScore; // Переменная принимает истинное значение если птица не пролетела препятствие, и ложное если пролетела
	public:
			 Obstacle(); // Конструктор по умолчанию

		// Метод который рисует препятствие на экране
		void draw(sf::RenderWindow& window); 

		// Метод который двигает препятствие
		void move(const sf::Time& deltaTime);

		// Метод который задаёт позицию препятствию
		void setPosition(const sf::Vector2f& pos);

		// Метод который засчитывает птице очко когда она пролетает препятствие
		void giveScoreTheBird(const Bird& bird, CounterScore& counter);
};

#endif