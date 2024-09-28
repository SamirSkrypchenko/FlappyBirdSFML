#include "Background.h"
#include "Consts.h"


Background::Background(const std::string& pathTexture)
{
	loadSprite(pathTexture);
}

int Background::loadSprite(const std::string& pathTexture)
{
	if (!texture.loadFromFile(pathTexture, sf::IntRect(0, 0, WIDTH, HEIGHT)))
		return EXIT_FAILURE;

	sprite.setTexture(texture);
}

void Background::draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
}