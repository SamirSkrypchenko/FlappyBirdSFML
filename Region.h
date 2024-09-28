#pragma once

#if !defined(REGION_H)
#define REGION_H

#include "Ground.h"
#include "Consts.h"
#include <SFML/Graphics.hpp>


class Region
{
	private:
		static const int MAX_COUNT_OF_GROUNDS = WIDTH / WIDTH_OF_GROUND + 3;
		Ground			 grounds[MAX_COUNT_OF_GROUNDS];
	public:
		sf::Vector2f	 position; // ������� ������� �������� ����

	public:
				         Region(); // ����������� �� ���������

		// ����� ������� ������ ������� ����� �� ������
		void			 draw(sf::RenderWindow& window);

		// ����� ������� ������� ������� ����� 
		void			 move(const sf::Time& dt);

		// ����� ������� ���������� ����� ������� ����� � ������ ����� �� ������ �����
		// ����� ������ ����� ������� ��������� ������ ������
		void			 transferThePartOfRegion();
};

#endif