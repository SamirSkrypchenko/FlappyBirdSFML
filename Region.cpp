#include "Region.h"


Region::Region()
{
	// ���������� ������� �����
	for (int i = 0; i < MAX_COUNT_OF_GROUNDS; i++)
	{
		sf::Vector2f pos = sf::Vector2f(i * WIDTH_OF_GROUND, HEIGHT - HEIGHT_OF_GROUND);
		grounds[i].position = pos;
	}

	// ������������� ������� ������� �������� ���� ������� �����
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
	static int index1 = 0; // ������ ����� ������� ��������� � ����� ����� �������
	static int index2 = MAX_COUNT_OF_GROUNDS - 1; // ������ ����� ������� ��������� � ������ ����� �������

	while (position.x <= WIDTH) // ���� ������ ����� ������� ��������� ������ ����
	{
		// ���� index1 >= MAX_COUNT_OF_GROUNDS �� ��� ������ ��� ����� ��� �������� 0 ����� ��������� � ����� ����� �������
		if (index1 >= MAX_COUNT_OF_GROUNDS) 
			index1 = 0;
			
		grounds[index1].position.x = grounds[index2].position.x + WIDTH_OF_GROUND; // ����������� ����� � ����� ���� �������
																				   // ��� �������� index1 ������� ����� 
																				   // ������� ��������� � ������ ����� �������
																				   // ��� �������� index2 � ���� ����� �����

		position.x = grounds[index1].position.x + WIDTH_OF_GROUND; // ��������� ������� �������� ������� ���� �������
		index2 = index1++; // ����������� index2 �������� index1, 
						   // ��� ��� ����� ��� �������� index1 ������ ��������� � ������ ����� �������.
						   // � ����� ����������� index1 �� �������
	}
}