#pragma once

#if !defined(BACKGROUND_H)
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <string.h>


class Background
{
	private:
		sf::Texture texture;
		sf::Sprite  sprite;

	private:
		// Метод который подгружает текстуру в спрайт 
		int         loadSprite(const std::string& pathTexture);
	public:
					Background(const std::string& pathTexture); // Конструктор
	
		// Метод который рисует задний Фон на экране
		void		draw(sf::RenderWindow& window) const;
};

#endif