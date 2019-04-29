#include "GameManager.h"


GameManager::GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc, MinesweeperView &mv)
	: introController(ic), minesweeperController(mc), scoreController(sc), minesweeperView(mv)
{

	state = INTRO;
}

void GameManager::updateState() {
	switch (state) {
	case INTRO:
		if (introController.isFinished()) {
			minesweeperView.clk.restart();
			state = GAME;
		}
		break;
	case GAME:
		if (minesweeperController.isFinished())
			state = SCORE;
		break;
	case SCORE:
		if (scoreController.isFinished()) {
			introController.resetState();
			minesweeperController.resetState();
			scoreController.resetState();
			state = INTRO;
		}
		break;
	}
}

void GameManager::handleEvent(sf::Event &event, sf::RenderWindow &win, int &width, int &height, GameMode &mode, MinesweeperBoard &board)
{
	switch (state) {
	case INTRO:
		introController.handleEvent(event, win, width, height, mode, board);
		break;
	case GAME:
		minesweeperController.handleEvent(event, board, win);
		break;
	case SCORE:
		scoreController.handleEvent(event, win);
		break;
	}
	updateState();
}

void GameManager::draw(sf::RenderWindow &win) {
	updateState();
	switch (state) {
	case INTRO:
		introController.draw(win);
		break;

	case GAME:
		minesweeperController.draw(win);
		break;

	case SCORE:
		scoreController.draw(win);
		break;
	}
}