#pragma once

#if !defined(BIRD_H)
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <string.h>


class Obstacle;


class Bird
{
	private:
		sf::Texture  texture;
		sf::Sprite   sprite;
		float		 speedY;
	public:
		sf::Vector2f position;
		enum states  { FLY, STAY }; // состояния птицы (полёт, покой)
		states		 state;
		bool		 canFlight;

	private:
		// Метод который подгружает текстуру в спрайт
		int			 loadSprite(const std::string& pathTexture);

		// Метод который позволяет птице подлетать
		void		 flight();
	public:
					 Bird(const std::string& pathTexture); // Конструктор

		// Метод который рисует птицу на экране
		void		 draw(sf::RenderWindow& window); 

		// Метод который проигрывает анимацию
		void		 animation();

		// Метод который поворачивает птицу
		void		 rotate(const sf::Time& dt);

		// метод заставляющий птицу падать вниз
		void		 gravity(const sf::Time& dt);

		// метод который проверяет столкновение птицы с землёй
		bool		 checkCollisionWithGround() const;

		// Метод который проверяет столкновение птицы с препятсвием
		bool		 checkColiisionWithObstacle(const Obstacle *obstacle) const;

		// Метод который считывает нажатие (в данном случае пробел для взлёта)
		void		 input();
};

#endif