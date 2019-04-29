#include "MinesweeperController.h"

MinesweeperController::MinesweeperController(MinesweeperView &v, MinesweeperBoard &b) :view(v), board(b)
{}

void MinesweeperController::handleEvent(sf::Event &event, MinesweeperBoard &board, sf::RenderWindow &win) {
	if (event.type == sf::Event::EventType::MouseButtonPressed) {
		for (int kolumna = 0; kolumna <= board.getBoardWidth(); kolumna++) {
			for (int wiersz = 0; wiersz <= board.getBoardHeight(); wiersz++) {
				if (view.pola[kolumna][wiersz].isMouseOver(win)) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						board.revealField(kolumna, wiersz);
						if (board.getGameState() != 0) {
							view.score = view.clk.getElapsedTime().asSeconds();
							std::cout << view.score;
							finished = true;
						}
					}
					else if (event.mouseButton.button == sf::Mouse::Right) {
						board.toggleFlag(kolumna, wiersz);
						if (board.getGameState() != 0) {
							view.score = view.clk.getElapsedTime().asSeconds();
							std::cout << view.score;
							finished = true;
						}
					}
				}
			}
		}
		
	}
	
}