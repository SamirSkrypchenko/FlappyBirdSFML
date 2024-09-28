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
		sf::Vector2f	 position; // позици€ правого верхнего угла

	public:
				         Region(); //  онструктор по умолчанию

		// ћетод который рисует участок земли на экране
		void			 draw(sf::RenderWindow& window);

		// ћетод который двигает участок земли 
		void			 move(const sf::Time& dt);

		// ћетод который перемещает часть участка земли с левого конца на правый конец
		// когда правый конец участка находитс€ внутри экрана
		void			 transferThePartOfRegion();
};

#endif