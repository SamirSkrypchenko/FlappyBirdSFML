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
					 CounterScore(); // ����������� �� ���������

					 CounterScore(const std::string& pathFont); // ����������� � ����� ����������

		// ����� ��� ��������� ������ � �����
		int		     loadFont(const std::string& pathFont);

		// ����� ������� ������ ����� �� ������
		void		 draw(sf::RenderWindow& window);

		// ����� ������� ���������� ���������� �����
		unsigned int getScore() const;

		// ����� ������� ����� �����
		void setText(unsigned int text);

		// �������� ������� �������������� �������
		unsigned int operator++();
};

#endif
