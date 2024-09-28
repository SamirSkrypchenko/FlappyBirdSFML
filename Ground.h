#pragma once

#if !defined(GROUND_H)
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <string.h>


class Ground
{
	private:
		sf::Texture  texture;
		sf::Sprite	 sprite;
	public:
		sf::Vector2f position;

	private:
		// Метод для подгрузки текстуры в спрайт
		int			 loadSprite(const std::string& pathTexture);
	public:
					 Ground(); // конструктор по умолчанию

				     Ground(const std::string& pathTexture); // Конструктор
		
		// Метод который рисует землю на экране
		void		 draw(sf::RenderWindow& window);
};

#endif