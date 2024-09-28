#include "Ground.h"


Ground::Ground()
{
	loadSprite("img/ground.png");
}

Ground::Ground(const std::string& pathTexture)
{
	loadSprite(pathTexture);
}

int Ground::loadSprite(const std::string& pathTexture)
{
	if (!texture.loadFromFile(pathTexture))
		return EXIT_FAILURE;

	sprite.setTexture(texture);
}

void Ground::draw(sf::RenderWindow& window)
{
	sprite.setPosition(position);
	window.draw(sprite);
}