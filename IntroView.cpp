#include "IntroView.h"
#include <cstdlib> // abort()


IntroView::IntroView() {

	if (!arial.loadFromFile("arial.ttf")) {
		abort();
	}
	if (!harington.loadFromFile("HARNGTON.ttf")) {
		abort();
	}

	//Background settings of Intro screen//
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(800, 800));
	background.setFillColor(sf::Color(50, 50, 50));

	//Title on Intro screen settings//
	title.setFont(harington);
	title.setString("Minesweeper");
	title.setPosition(215, 0);
	title.setFillColor(sf::Color::Black);
	title.setCharacterSize(70);

	//Name on Intro screen settings//
	name.setFont(arial);
	name.setString("Michal Grad");
	name.setPosition(10, 10);
	name.setFillColor(sf::Color::Black);
	name.setCharacterSize(20);

	//Index on Intro screen settings//
	index.setFont(arial);
	index.setString("249306");
	index.setPosition(10, 35);
	index.setFillColor(sf::Color::Black);
	index.setCharacterSize(20);

	//Group on Intro screen settings//
	group.setFont(arial);
	group.setString("wtorek - 17:15");
	group.setPosition(10, 60);
	group.setFillColor(sf::Color::Black);
	group.setCharacterSize(20);

	//Small board size button settings//
	small = Button("10x10", { 80,30 }, 20, sf::Color::White, sf::Color::Black, 5, sf::Color::Black);
	small.setPosition(sf::Vector2f(100, 400));
	small.setFont(arial);
	small.setTextPosition({ 113,402 });

	//Medium board size button settings//
	medium = Button("20x15", { 80,30 }, 20, sf::Color::White, sf::Color::Black, 5, sf::Color::Black);
	medium.setPosition(sf::Vector2f(230, 400));
	medium.setFont(arial);
	medium.setTextPosition({ 243,402 });

	//Big board size button settings//
	big = Button("25x25", { 80,30 }, 20, sf::Color::White, sf::Color::Black, 5, sf::Color::Black);
	big.setPosition(sf::Vector2f(360, 400));
	big.setFont(arial);
	big.setTextPosition({ 373,402 });

	//Easy level button settings//
	easy = Button("Easy", { 80,30 }, 20, sf::Color::White, sf::Color::Black, 5, sf::Color::Black);
	easy.setPosition(sf::Vector2f(100, 500));
	easy.setFont(arial);
	easy.setTextPosition({ 119,502 });

	//Normal level button settings//
	normal = Button("Normal", { 80,30 }, 20, sf::Color::White, sf::Color::Black, 5, sf::Color::Black);
	normal.setPosition(sf::Vector2f(230, 500));
	normal.setFont(arial);
	normal.setTextPosition({ 238,502 });

	//Hard level button settings//
	hard = Button("Hard", { 80,30 }, 20, sf::Color::White, sf::Color::Black, 5, sf::Color::Black);
	hard.setPosition(sf::Vector2f(360, 500));
	hard.setFont(arial);
	hard.setTextPosition({ 379,502 });

	//Start button settings
	start = Button("START", { 120,120 }, 35, sf::Color::White, sf::Color::Black, 5, sf::Color::Black);
	start.setPosition(sf::Vector2f(550, 407));
	start.setFont(arial);
	start.setTextPosition({ 554,445 });
}

void IntroView::draw(sf::RenderWindow &win) {
	win.draw(background);

	win.draw(title);
	win.draw(name);
	win.draw(index);
	win.draw(group);

	small.drawTo(win);
	medium.drawTo(win);
	big.drawTo(win);

	easy.drawTo(win);
	normal.drawTo(win);
	hard.drawTo(win);

	start.drawTo(win);
}