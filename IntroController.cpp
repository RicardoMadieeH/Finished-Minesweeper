#include "IntroController.h"

IntroController::IntroController(IntroView &v, MinesweeperBoard &b) : view(v), board(b)
{}

void IntroController::handleEvent(sf::Event &event, sf::RenderWindow &win, int &width, int &height, GameMode &mode, MinesweeperBoard &board) {
	if (event.type == sf::Event::MouseMoved) {

		if (view.start.isMouseOver(win)) {
			view.start.setBackColor(sf::Color(255, 0, 144));
		}
		else {
			view.start.setBackColor(sf::Color::White);
		}
	}
	else if (event.type == sf::Event::EventType::MouseButtonPressed) {
		if (view.small.isMouseOver(win)) {
			width = 10;
			height = 10;
			view.small.setBackColor(sf::Color(10, 200, 100));
			view.medium.setBackColor(sf::Color::White);
			view.big.setBackColor(sf::Color::White);
		}
		if (view.medium.isMouseOver(win)) {
			width = 20;
			height = 15;
			view.medium.setBackColor(sf::Color(10, 200, 100));
			view.small.setBackColor(sf::Color::White);
			view.big.setBackColor(sf::Color::White);
		}
		if (view.big.isMouseOver(win)) {
			width = 25;
			height = 25;
			view.big.setBackColor(sf::Color(10, 200, 100));
			view.medium.setBackColor(sf::Color::White);
			view.small.setBackColor(sf::Color::White);
		}
		if (view.easy.isMouseOver(win)) {
			mode = EASY;
			view.easy.setBackColor(sf::Color(10, 200, 100));
			view.normal.setBackColor(sf::Color::White);
			view.hard.setBackColor(sf::Color::White);
		}
		if (view.normal.isMouseOver(win)) {
			mode = NORMAL;
			view.normal.setBackColor(sf::Color(10, 200, 100));
			view.easy.setBackColor(sf::Color::White);
			view.hard.setBackColor(sf::Color::White);
		}
		if (view.hard.isMouseOver(win)) {
			mode = HARD;
			view.hard.setBackColor(sf::Color(10, 200, 100));
			view.easy.setBackColor(sf::Color::White);
			view.normal.setBackColor(sf::Color::White);
		}

		if (view.start.isMouseOver(win)) {
			if (width == 0 || (mode != 1 && mode != 2 && mode != 3)) {
				finished = false;
			}
			else {
				board = MinesweeperBoard(width, height, mode);
				finished = true;
			}
		}

	}


}