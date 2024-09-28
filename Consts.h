#pragma once

#if !defined(CONSTS_H)
#define CONSTS_H

#include <iostream>
#include <SFML/Graphics.hpp>



const int FPS = 60;
const int WIDTH = 768;
const int HEIGHT = 1024;
const int WIDTH_OF_GROUND = 37;
const int HEIGHT_OF_GROUND = 128;
const int LENGTH_OF_PIPE = 138;
const float PI = 3.14159265;
const float GRAVITY = 3000.f; // ��������� ���������� �������
const float SPEEDY_MAX = GRAVITY * 20.f; // ����������� �������� �� Y
const float SPEED_ELEMENTS = 300.f; // �������� ��������� ���� (�����, ������)
const float SPAWN_TIME = 2.f; // ����� ������� ������ ������ � ������� ������ ����������� ����� ������������ ����� ����������� (� ��������)
const float DISTANCE_BETWEEN_OBSTACLES = WIDTH / 2; // ��������� ����� ����� ��������� �������������
const float TIME_BETWEEN_FRAMES = 0.1F; // ����� ����� ����� ��������� ������� �����
const sf::String windowTitle = "Flappy Bird SFML";
const sf::Vector2u REC_COLL_SHAPE_OF_THE_BIRD = sf::Vector2u(40, 50); // ������� �����

#endif