#include "Region.h"


Region::Region()
{
	// Заполнение участка землёй
	for (int i = 0; i < MAX_COUNT_OF_GROUNDS; i++)
	{
		sf::Vector2f pos = sf::Vector2f(i * WIDTH_OF_GROUND, HEIGHT - HEIGHT_OF_GROUND);
		grounds[i].position = pos;
	}

	// устанавливаем позицию парвого верхнего угла участка земли
	position = grounds[MAX_COUNT_OF_GROUNDS - 1].position;
	position.x += WIDTH_OF_GROUND;
}

void Region::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_COUNT_OF_GROUNDS; i++)
	{
		grounds[i].draw(window);
	}
}

void Region::move(const sf::Time& dt)
{
	sf::Time dtTemp = dt;

	for (int i = 0; i < MAX_COUNT_OF_GROUNDS; i++)
	{
		grounds[i].position.x -= SPEED_ELEMENTS * dtTemp.asSeconds();
	}

	position.x -= SPEED_ELEMENTS * dtTemp.asSeconds();
	transferThePartOfRegion();
}

void Region::transferThePartOfRegion()
{
	static int index1 = 0; // Индекс земли которая находится в левом конце участка
	static int index2 = MAX_COUNT_OF_GROUNDS - 1; // Индекс земли которая находится в правом конце участка

	while (position.x <= WIDTH) // пока правый конец участка находится внутри окна
	{
		// если index1 >= MAX_COUNT_OF_GROUNDS то это значит что земля под индексом 0 снова находится в левом конце участка
		if (index1 >= MAX_COUNT_OF_GROUNDS) 
			index1 = 0;
			
		grounds[index1].position.x = grounds[index2].position.x + WIDTH_OF_GROUND; // присваиваем земле в левом краю участка
																				   // под индексом index1 позицию земли 
																				   // которая находится в правом конце участка
																				   // под индексом index2 и плюс длина земли

		position.x = grounds[index1].position.x + WIDTH_OF_GROUND; // обновляем позицию верхнего правого угла участка
		index2 = index1++; // присваиваем index2 значание index1, 
						   // так как земля под индексом index1 теперь находится в правом конце участка.
						   // А затем увеличиваем index1 на единицу
	}
}