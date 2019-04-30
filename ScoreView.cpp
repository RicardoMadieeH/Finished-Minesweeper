#include "ScoreView.h"

ScoreView::ScoreView(MinesweeperBoard &b, MinesweeperView &mv):board(b), minesweeperView(mv) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "error loading font" << std::endl;
	}

	koniec.setBackColor(sf::Color(230, 230, 230));
	koniec.setFont(font);
	koniec.setOutline(2, sf::Color(100, 100, 100));
	koniec.setTextColor(sf::Color::Black);
	koniec.sizeSet(sf::Vector2f(300, 50));
	koniec.setPosition(sf::Vector2f(250, 0));


	yS.setFillColor(sf::Color::White);
	yS.setCharacterSize(40);
	yS.setString("Your score: ");
	yS.setPosition(sf::Vector2f(25, 150));
	yS.setFont(font);

	hS.setFillColor(sf::Color::White);
	hS.setCharacterSize(40);
	hS.setString("Highest score: ");
	hS.setPosition(sf::Vector2f(25, 200));
	hS.setFont(font);

	yourScore.setFont(font);
	yourScore.setCharacterSize(40);
	yourScore.setFillColor(sf::Color::White);
	yourScore.setPosition(sf::Vector2f(250, 150));

	highScore.setFont(font);
	highScore.setCharacterSize(40);
	highScore.setFillColor(sf::Color::White);
	highScore.setPosition(sf::Vector2f(300, 200));

	tryAgain.setBackColor(sf::Color(180, 180, 180));
	tryAgain.setFont(font);
	tryAgain.sizeSet(sf::Vector2f(200, 200));
	tryAgain.setTextString("Try Again", 40);
	tryAgain.setTextColor(sf::Color::Black);
	tryAgain.setOutline(2, sf::Color::Yellow);
	tryAgain.setPosition(sf::Vector2f(100, 350));
	tryAgain.setTextPosition(sf::Vector2f(117, 420));

	exit.setBackColor(sf::Color(180, 180, 180));
	exit.setFont(font);
	exit.sizeSet(sf::Vector2f(200, 200));
	exit.setTextString("Exit", 60);
	exit.setTextColor(sf::Color::Black);
	exit.setOutline(2, sf::Color::Yellow);
	exit.setPosition(sf::Vector2f(500, 350));
	exit.setTextPosition(sf::Vector2f(547, 410));
}


void ScoreView::draw(sf::RenderWindow &win) {
	

	if (board.getGameState() == FINISHED_WIN) {
		koniec.setTextString("WYGRALES", 45);
		koniec.setTextPosition(sf::Vector2f(275, -5));
	}
	else if (board.getGameState() == FINISHED_LOSS) {
		koniec.setTextPosition(sf::Vector2f(250, -5));
		koniec.setTextString("PRZEGRALES", 45);
	}

	switch (board.getGameMode()) {
	case EASY:
		switch (board.getBoardWidth() * board.getBoardHeight()) {
		case 100:
			endScore = minesweeperView.score * 50;
			break;
			
		case 300:
			endScore = minesweeperView.score * 40;
			break;

		case 625:
			endScore = minesweeperView.score * 30;
			break;
		}
		break;

	case NORMAL:
		switch (board.getBoardWidth() * board.getBoardHeight()) {
		case 100:
			endScore = minesweeperView.score * 40;
			break;

		case 300:
			endScore = minesweeperView.score * 30;
			break;

		case 625:
			endScore = minesweeperView.score * 20;
			break;
		}
		break;

	case HARD:
		switch (board.getBoardWidth() * board.getBoardHeight()) {
		case 100:
			endScore = minesweeperView.score * 30;
			break;

		case 300:
			endScore = minesweeperView.score * 20;
			break;

		case 625:
			endScore = minesweeperView.score * 10;
			break;
		}
		break;
	}

	koniec.drawTo(win);
	
	if (board.getGameState() == FINISHED_WIN) {
		setScore();
	}
	

	if (board.getGameState() == FINISHED_WIN) {
		win.draw(yS);
	}
	
	
	win.draw(hS);

	scoreString = std::to_string(endScore);
	yourScore.setString(scoreString);
	if (board.getGameState() == FINISHED_WIN) {
		win.draw(yourScore);
	}

	highscoreString = std::to_string(bestScore);
	highScore.setString(highscoreString);
	win.draw(highScore);

	tryAgain.drawTo(win);
	exit.drawTo(win);

}

void ScoreView::setScore() {
	std::fstream highscore;
	highscore.open("highscores.txt", std::ios::in /*| std::ios::out | std::ios::trunc*/);
	
	if (!highscore) {
		highscore.close();
		std::ofstream temp("highscores.txt");
		temp << 999999999 << std::endl;
		temp.close();
		highscore.open("highscores.txt", std::ios::in /*| std::ios::out | std::ios::trunc*/);
	}

	std::string line;

	std::getline(highscore, line);

	std::istringstream kopytko(line);

	kopytko >> bestScore;

	highscore.close();

	if (bestScore > endScore) {
		highscore.open("highscores.txt", std::ios::trunc);
		highscore.close();
		highscore.open("highscores.txt", std::ios::out);
		highscore << scoreString;
		highscore.close();
	}
}