#include <SFML/Graphics.hpp>
#include "ScoreController.h"
#include "ScoreView.h"
#include "IntroController.h"
#include "IntroView.h"
#include "MinesweeperController.h"
#include "MinesweeperView.h"
#include "MinesweeperBoard.h"
#include "Button.h"
#include "Textbox.h"
#include <ctime>




#include "GameManager.h"


int main() {
	srand(time(0));
	int width = 0;
	int height = 0;
	GameMode mode = CLEAR;

	

	sf::Font arial;
	if (!arial.loadFromFile("arial.ttf")) {
		abort();
	}

	MinesweeperBoard board;


	// Create the main window
	sf::RenderWindow win(sf::VideoMode(800, 600), "Minesweeper");

	IntroView iv;
	IntroController ic(iv, board);
	// generalnie - do kontrolera przeka¿emy referencje na widok i model, czyli
	// IntroController ic(iv, im);
	// w tym przypadku model jest tak prosty, ¿e "zintegrowa³em" go z widokiem

	// fake - zast¹pcie Wasz¹ klas¹, dodajcie model planszy
	

	MinesweeperView mv(board, 20, 30, 40);
	MinesweeperController mc(mv, board);
	

	// uwagi jak do Intro
	ScoreView sv(board, mv);
	ScoreController sc(sv);

	GameManager gm(ic, mc, sc, mv);

	

	// Start the game loop
	while (win.isOpen()) {
		// Process events
		sf::Event event;
		while (win.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed) {
				win.close();
			}



			gm.handleEvent(event, win, width, height, mode, board);
			
		}

		// Clear screen
		win.clear();

		// Draw current state
		gm.draw(win);


		// Update the window
		win.display();
	}

	return EXIT_SUCCESS;
}