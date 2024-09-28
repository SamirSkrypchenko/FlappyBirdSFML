#pragma once

#if !defined(PIPE_H)
#define PIPE_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Pipe
{
	private:
		sf::Texture  texture;
		sf::Sprite   sprite;
	public:
		sf::Vector2f position;

	private:
		// ����� ������� ���������� �������� � ������
		int			 loadSprite(const std::string& pathTexture);
	public:
					 Pipe(); // ����������� �� ���������

					 Pipe(const std::string& pathTexture); // ����������� � ����������

		// ����� ������� ������� �����
		void		 move(const sf::Time& deltaTime);

		// ����� ������� ������ ����� �� ������
		void		 draw(sf::RenderWindow& window);

		// ����� ������� ������������ ����� �� ���� angle (� ��������)
		void		 rotate(const float angle);

		// ����� ������� ���������� ����� �����
		const int&	 getLength() const { return texture.getSize().x; }

};

#endif