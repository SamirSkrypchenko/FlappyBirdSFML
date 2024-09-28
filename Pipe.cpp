#include "Pipe.h"
#include "Consts.h"


Pipe::Pipe()
{
	loadSprite("img/pipe.png");
	sprite.setPosition(position);
}

Pipe::Pipe(const std::string& pathTexture)
{
	loadSprite(pathTexture);
	sprite.setPosition(position);
}

int Pipe::loadSprite(const std::string& pathTexture)
{
	if (!texture.loadFromFile(pathTexture))
		return EXIT_FAILURE;
	
	sprite.setTexture(texture);
}

void Pipe::move(const sf::Time& deltaTime)
{
	position.x -= SPEED_ELEMENTS * deltaTime.asSeconds();
}

void Pipe::draw(sf::RenderWindow& window)
{
	sprite.setPosition(position);
	window.draw(sprite);
}

void Pipe::rotate(const float angle)
{
	sprite.rotate(angle);
}

