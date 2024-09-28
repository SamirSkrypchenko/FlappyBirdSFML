#pragma once

#if !defined(COUNTERSCORE_H)
#define COUNTERSCORE_H

#include <SFML/Graphics.hpp>


class CounterScore
{
	private:
		sf::Font font;
		unsigned int textSize;
		unsigned int score;
	public:
		sf::Text text;

	public:
					 CounterScore(); // Конструктор по умолчанию

					 CounterScore(const std::string& pathFont); // Конструктор с одним параметром

		// Метод для подгрузки шрифта в текст
		int		     loadFont(const std::string& pathFont);

		// Метод который рисует текст на экране
		void		 draw(sf::RenderWindow& window);

		// Метод который возвращает количество очков
		unsigned int getScore() const;

		// Метод который задаёт текст
		void setText(unsigned int text);

		// Оператор который инкрементирует счетчик
		unsigned int operator++();
};

#endif
