#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

enum GameMode {
	DEBUG, EASY, NORMAL, HARD, TEST, TEST2, CLEAR
};
enum GameState {
	RUNNING, FINISHED_WIN, FINISHED_LOSS
};

struct Field {
	bool hasMine = false;
	bool hasFlag = false;
	bool isRevealed = false;
};

class MinesweeperBoard {
	Field board[100][100];
	int width;
	int height;
	GameMode mode;
	GameState state;


public:


	explicit MinesweeperBoard() {};

	MinesweeperBoard(int width, int height, GameMode gameMode);

	void debug_display() const;

	int getBoardWidth() const;

	int getBoardHeight() const;

	double getMineCount() const;

	int countMines(int x, int y) const;

	bool hasFlag(int x, int y) const;

	void toggleFlag(int x, int y);

	void revealField(int x, int y);

	void revealIfBlank(int x, int y);

	bool isRevealed(int x, int y) const;

	bool hasMine(int x, int y) const;

	GameState getGameState() const;

	char getFieldInfo(int x, int y) const;

	bool isInBoard(int x, int y) const;

	GameMode getGameMode() const;
};

#endif