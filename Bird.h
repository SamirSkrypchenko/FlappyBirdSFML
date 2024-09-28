#pragma once

#if !defined(BIRD_H)
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <string.h>


class Obstacle;


class Bird
{
	private:
		sf::Texture  texture;
		sf::Sprite   sprite;
		float		 speedY;
	public:
		sf::Vector2f position;
		enum states  { FLY, STAY }; // ��������� ����� (����, �����)
		states		 state;
		bool		 canFlight;

	private:
		// ����� ������� ���������� �������� � ������
		int			 loadSprite(const std::string& pathTexture);

		// ����� ������� ��������� ����� ���������
		void		 flight();
	public:
					 Bird(const std::string& pathTexture); // �����������

		// ����� ������� ������ ����� �� ������
		void		 draw(sf::RenderWindow& window); 

		// ����� ������� ����������� ��������
		void		 animation();

		// ����� ������� ������������ �����
		void		 rotate(const sf::Time& dt);

		// ����� ������������ ����� ������ ����
		void		 gravity(const sf::Time& dt);

		// ����� ������� ��������� ������������ ����� � �����
		bool		 checkCollisionWithGround() const;

		// ����� ������� ��������� ������������ ����� � �����������
		bool		 checkColiisionWithObstacle(const Obstacle *obstacle) const;

		// ����� ������� ��������� ������� (� ������ ������ ������ ��� �����)
		void		 input();
};

#endif