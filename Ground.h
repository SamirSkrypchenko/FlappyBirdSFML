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
		// ����� ��� ��������� �������� � ������
		int			 loadSprite(const std::string& pathTexture);
	public:
					 Ground(); // ����������� �� ���������

				     Ground(const std::string& pathTexture); // �����������
		
		// ����� ������� ������ ����� �� ������
		void		 draw(sf::RenderWindow& window);
};

#endif