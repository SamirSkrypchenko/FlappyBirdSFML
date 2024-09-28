#include "CounterScore.h"
#include "Consts.h"


CounterScore::CounterScore() : score(0), textSize(75)
{ 
	loadFont("fonts/PixelifySans-SemiBold.ttf");
	text.setCharacterSize(textSize);
	text.setOrigin(textSize / 2, textSize / 2);
	text.setPosition(sf::Vector2f(WIDTH / 2, 50.f));
	text.setFillColor(sf::Color::White);
	setText(0);
}

CounterScore::CounterScore(const std::string& pathFont) : score(0), textSize(50)
{
	loadFont(pathFont);
	text.setCharacterSize(textSize);
	text.setOrigin(textSize / 2, textSize / 2);
	text.setPosition(sf::Vector2f(WIDTH / 2, 50.f));
	text.setFillColor(sf::Color::White);
	setText(0);
}

int CounterScore::loadFont(const std::string& pathFont)
{
	if (!font.loadFromFile(pathFont))
		return EXIT_FAILURE;

	text.setFont(font);
}

void CounterScore::setText(unsigned int val)
{
	text.setString(std::to_string(val));
}

void CounterScore::draw(sf::RenderWindow& window)
{
	window.draw(text);
}

unsigned int CounterScore::getScore() const { return score; }

unsigned int CounterScore::operator++() { return ++score; }