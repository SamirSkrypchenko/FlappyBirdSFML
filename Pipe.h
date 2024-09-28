#pragma once

#if !defined(PIPE_H)
#define PIPE_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Pipe
{
	private:
		sf::Texture  texture;
		sf::Sprite   sprite;
	public:
		sf::Vector2f position;

	private:
		// Метод который подгружает текстуру в спрайт
		int			 loadSprite(const std::string& pathTexture);
	public:
					 Pipe(); // конструктор по умолчанию

					 Pipe(const std::string& pathTexture); // конструктор с параметром

		// Метод который двигает трубу
		void		 move(const sf::Time& deltaTime);

		// Метод который рисует трубу на экране
		void		 draw(sf::RenderWindow& window);

		// Метод который поворачивает трубу ну угол angle (В градусах)
		void		 rotate(const float angle);

		// Метод который возвращает длину трубы
		const int&	 getLength() const { return texture.getSize().x; }

};

#endif