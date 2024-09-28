#pragma once

#if !defined(GAME_H)
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Bird.h"
#include "Region.h"
#include "ObstaclesSpawner.h"
#include "CounterScore.h"


class Game
{
	private:
		sf::Texture	     textureBackground;
		sf::RenderWindow window;
		Background		 background;
		Bird			 bird;
		Region			 region;
		CounterScore	 counter;
	public:
		ObstaclesSpawner spawner;

	private:
		// ���� ����� ��������� ������� (����� ��� ������� �������, ��� �������� ������� ����)
		void		     processEvents();

		// ���� ����� ��������� ������ ����.
		//  �������� deltaTime ��� ������� ������� ����� ����� ��������� �������
		void			 update(sf::Time& deltaTime);

		// ���� ����� ������ ������� ������ ����
		void			 render();
	public:
					     Game(); // �����������

		// ����� ��� ������� ����
		void		     run();
};	

#endif