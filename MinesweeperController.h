#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MinesweeperView.h"
#include "Button.h"

class MinesweeperController {
	bool finished = false;

	MinesweeperView & view;
	MinesweeperBoard &board;
	// ... & model;
public:
	explicit MinesweeperController(MinesweeperView & v, MinesweeperBoard &b);
public:
	void handleEvent(sf::Event &event, MinesweeperBoard &board, sf::RenderWindow &win);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
	bool resetState() { finished = false; return finished; }
};



#endif // MINESWEEPERCONTROLLER_H
