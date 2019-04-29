#ifndef UNTITLED2_MINESWEEPERVIEW_H
#define UNTITLED2_MINESWEEPERVIEW_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "Button.h"

class MinesweeperView {

	MinesweeperBoard &board;
	int wielkoscPol;
	int offsetX;
	int offsetY;
	sf::RectangleShape defaultField;
	sf::RectangleShape flaggedField;
	sf::RectangleShape revealedMineField;
	sf::RectangleShape revealedNotMineField;
	int width, height;

	sf::Font font;
	sf::Text txt;
	sf::Texture texture;
	sf::Sprite flag;
	Button koniec;
	Button time;
public:
	Button pola[40][30];
	sf::Clock clk;
	int score = 0;
	
	MinesweeperView(MinesweeperBoard &b, int wielkoscPol, int startX, int startY);

	void draw(sf::RenderWindow &win);
};




#endif //UNTITLED2_MINESWEEPERVIEW_H
