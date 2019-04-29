#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &v) : view(v)
{}

void ScoreController::handleEvent(sf::Event &event, sf::RenderWindow &win) {
	
	if (event.type == sf::Event::MouseMoved) {

		if (view.tryAgain.isMouseOver(win)) {
			view.tryAgain.setBackColor(sf::Color::Green);
		}
		else {
			view.tryAgain.setBackColor(sf::Color(180, 180, 180));
		}

		if (view.exit.isMouseOver(win)) {
			view.exit.setBackColor(sf::Color::Red);
		}
		else {
			view.exit.setBackColor(sf::Color(180, 180, 180));
		}
	}
	else if (event.type == sf::Event::EventType::MouseButtonPressed) {
		if (view.tryAgain.isMouseOver(win)) {
			finished = true;
		}
		else if (view.exit.isMouseOver(win)) {
			win.close();
		}
	}
}
