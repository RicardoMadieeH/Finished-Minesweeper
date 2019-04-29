#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "MinesweeperBoard.h"

class IntroController {
	bool finished = false;
	IntroView & view;
	MinesweeperBoard &board;
	// IntroModel & model;
public:
	explicit IntroController(IntroView & iv, MinesweeperBoard &b);

	void handleEvent(sf::Event &event, sf::RenderWindow &win, int &width, int &height, GameMode &mode, MinesweeperBoard &board);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
	bool resetState() { finished = false; return finished; }
};


#endif // INTROCONTROLLER_H
