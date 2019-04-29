#include "MinesweeperView.h"

MinesweeperView::MinesweeperView(MinesweeperBoard &b, int wielkoscPol, int offsetX, int offsetY)
	: board(b), wielkoscPol(wielkoscPol), offsetX(offsetX), offsetY(offsetY) {

	if (!texture.loadFromFile("flag.png")) {
		std::cout << "error loading flag" << std::endl;
	}

	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "error loading arial" << std::endl;
	}

	flag.setTexture(texture);
}

void MinesweeperView::draw(sf::RenderWindow &win) {
	int kolumna = 0;
	int wiersz = 0;
	float xTextOffset = 0;
	float yTextOffset = 0;

	int width = board.getBoardWidth();
	int height = board.getBoardHeight();

	if (width == 10) {
		wielkoscPol = 45;
		xTextOffset = 11;
		yTextOffset = -4;

	}
	else if (width == 20) {
		wielkoscPol = 25;
		xTextOffset = 5;
		yTextOffset = -2;
	}
	else {
		wielkoscPol = 20;
		xTextOffset = 4;
		yTextOffset = -1;
	}
	

	// draw everything here...
	// window.draw(...);
	for (int idx = offsetX; idx <= board.getBoardWidth() * wielkoscPol + 40; idx = idx + wielkoscPol + 1) {
		wiersz = 0;
		for (int idy = offsetY; idy <= board.getBoardHeight() * wielkoscPol + 45; idy = idy + wielkoscPol + 1) {
			if (board.getFieldInfo(kolumna, wiersz) == '_') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(192, 192, 192));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setTextString("", 0);
				pola[kolumna][wiersz].drawTo(win);
				
			}
			else if (board.getFieldInfo(kolumna, wiersz) == 'F') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(192,192,192));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("F", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color::Red);
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == 'x') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(180, 180, 180));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("X", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color::Black);
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == ' ') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '1') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("1", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color::Blue);
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '2') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].drawTo(win);
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("2", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color::Green);
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '3') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("3", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color::Red);
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '4') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("4", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color(220, 30, 100));
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '5') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("5", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color(200, 100, 50));
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '6') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("7", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color(100, 200, 40));
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '7') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("7", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color(100, 80, 240));
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			else if (board.getFieldInfo(kolumna, wiersz) == '8') {
				pola[kolumna][wiersz].sizeSet(sf::Vector2f(wielkoscPol, wielkoscPol));
				pola[kolumna][wiersz].setBackColor(sf::Color(140, 140, 140));
				pola[kolumna][wiersz].setOutline(0, sf::Color::Black);
				pola[kolumna][wiersz].setPosition(sf::Vector2f(idx, idy));
				pola[kolumna][wiersz].setFont(font);
				pola[kolumna][wiersz].setTextString("8", wielkoscPol * 0.9);
				pola[kolumna][wiersz].setTextColor(sf::Color(20, 240, 240));
				pola[kolumna][wiersz].setTextPosition(sf::Vector2f(idx + xTextOffset, idy + yTextOffset));
				pola[kolumna][wiersz].drawTo(win);
			}
			wiersz++;
		}
		kolumna++;
	}
	
	const unsigned int seconds = static_cast<unsigned int>(clk.getElapsedTime().asSeconds());

	time.sizeSet(sf::Vector2f(120, 60));
	time.setBackColor(sf::Color::White);
	time.setOutline(2, sf::Color::Yellow);
	time.setFont(font);
	time.setTextColor(sf::Color::Red);
	time.setPosition(sf::Vector2f(600, 50));
	time.setTextString(std::to_string(seconds), 50);
	time.setTextPosition(sf::Vector2f(605, 55));
	

	time.drawTo(win);
	
	
}

