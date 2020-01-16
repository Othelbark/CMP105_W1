#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect0.setSize(sf::Vector2f(100, 100));
	rect0.setPosition(150, 150);
	rect0.setFillColor(sf::Color::Red);

	rect1.setSize(sf::Vector2f(60, 60));
	rect1.setPosition(170, 170);
	rect1.setFillColor(sf::Color::Green);

	rect2.setSize(sf::Vector2f(20, 20));
	rect2.setPosition(190, 190);
	rect2.setFillColor(sf::Color::Blue);
	
	rectBottomLeft.setSize(sf::Vector2f(30, 80));
	rectBottomLeft.setFillColor(sf::Color::Green);

	sf::Vector2u pos = window->getSize();
	sf::Vector2f size = rectBottomLeft.getSize();
	rectBottomLeft.setPosition(pos.x - size.x, pos.y - size.y);

	circle.setRadius(50);
	circle.setPosition(550, 287);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Red);

	// initialise text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(540, 0);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	sf::Vector2f size = rectBottomLeft.getSize();
	rectBottomLeft.setPosition(pos.x - size.x, pos.y - size.y);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect0);
	window->draw(rect1);
	window->draw(rect2);

	window->draw(rectBottomLeft);

	window->draw(circle);

	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));  //100, 149, 237
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}