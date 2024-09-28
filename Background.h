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
		// ����� ������� ���������� �������� � ������ 
		int         loadSprite(const std::string& pathTexture);
	public:
					Background(const std::string& pathTexture); // �����������
	
		// ����� ������� ������ ������ ��� �� ������
		void		draw(sf::RenderWindow& window) const;
};

#endif