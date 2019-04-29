#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "IntroController.h"
#include "MinesweeperController.h"
#include "ScoreController.h"
#include "MinesweeperView.h"

class GameManager {
	IntroController &introController;
	MinesweeperController &minesweeperController;
	ScoreController &scoreController;
	MinesweeperView &minesweeperView;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc, MinesweeperView &mv);

	void draw(sf::RenderWindow &win);

	void handleEvent(sf::Event &event, sf::RenderWindow &win, int &width, int &height, GameMode &mode, MinesweeperBoard &board);
};


#endif //UNTITLED2_GAMEMANAGER_H
