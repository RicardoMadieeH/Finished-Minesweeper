#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <SFML/Graphics.hpp>
#include "Textbox.h"
#include "Button.h"
#include "MinesweeperBoard.h"
#include "MinesweeperView.h"
#include <fstream>
#include <iostream>

class ScoreView {
	
	sf::Font font;

	int endScore;
	int bestScore;

	MinesweeperBoard &board;
	MinesweeperView &minesweeperView;

	std::ofstream highscore;
	
	std::string scoreString;
	std::string highscoreString;

	sf::Text yS;
	sf::Text hS;
	sf::Text yourScore;
	sf::Text highScore;

	Button koniec;
	
	
public:

	Button tryAgain;
	Button exit;

	ScoreView(MinesweeperBoard &b, MinesweeperView &mv);

	void draw(sf::RenderWindow &win);

	void setScore();
};


#endif //UNTITLED2_SCOREVIEW_H
