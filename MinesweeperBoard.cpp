#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode gameMode) :
	state(RUNNING) {
	MinesweeperBoard::width = width;
	MinesweeperBoard::height = height;
	MinesweeperBoard::mode = gameMode;
	for (int idx = 0; idx <= (width); idx++) {
		for (int idy = 0; idy <= (height); idy++) {
			board[idx][idy].hasMine = false;
			board[idx][idy].hasFlag = false;
			board[idx][idy].isRevealed = false;
		}
	}

	if (gameMode == EASY) {
		double mines;
		mines = 0.1 * width * height;

		for (int i = 1; i <= mines;) {
			int x = rand() % (width);
			int y = rand() % (height);
			if (board[x][y].hasMine == 0) {
				board[x][y].hasMine = true;
				i++;
			}
		}
	}
	else if (gameMode == NORMAL) {
		double mines;
		mines = 0.2 * width * height;

		for (int i = 1; i <= mines;) {
			int x = rand() % (width);
			int y = rand() % (height);
			if (board[x][y].hasMine == 0) {
				board[x][y].hasMine = true;
				i++;
			}
		}
	}
	else if (gameMode == HARD) {
		double mines;
		mines = 0.3 * width * height;

		for (int i = 1; i <= mines;) {
			int x = rand() % (width);
			int y = rand() % (height);
			if (board[x][y].hasMine == 0) {
				board[x][y].hasMine = true;
				i++;
			}
		}
	}
	else if (gameMode == DEBUG) {
		for (int idx = 0; idx <= (width - 1); idx++) {
			board[idx][0].hasMine = true;
		}


		for (int idx = 0; idx <= (width - 1); idx++) {
			for (int idy = 0; idy <= (height - 1); idy++) {
				if (idx == idy) {
					board[idx][idy].hasMine = true;
				}
			}
		}


		for (int idx = 0; idx <= (width - 1); idx++) {
			for (int idy = 0; idy <= (height - 1); idy++) {
				if (idx == 0 && idy % 2 == 0)
					board[idx][idy].hasMine = true;
			}
		}
	}
	else if (gameMode == TEST) {
		double mines;
		mines = width;

		for (int idx = 0; idx <= (width - 1); idx++) {
			for (int idy = 0; idy <= (height - 1); idy++) {
				board[idx][idy].hasMine = true;

			}
		}
	}
	else if (gameMode == TEST2) {

		for (int idx = 0; idx <= (width - 1); idx++) {
			board[idx][0].hasMine = true;
			board[idx][9].hasMine = true;
			for (int idy = 0; idy <= (height - 1); idy++) {
				board[0][idy].hasMine = true;
				board[9][idy].hasMine = true;

			}
		}
	}
	else if (gameMode == CLEAR) {
		for (int idx = 0; idx <= (width - 1); idx++) {
			for (int idy = 0; idy <= (height - 1); idy++) {
				board[idx][idy].hasMine = false;

			}
		}
	}
}

void MinesweeperBoard::debug_display() const {
	for (int idy = 0; idy <= (height - 1); idy++) {
		for (int idx = 0; idx <= (width - 1); idx++) {
			//Czy na polu znajduje siê mina

			std::cout << "(";
			if (board[idx][idy].hasMine == 0) {
				std::cout << '.';
			}
			else {
				std::cout << 'M';
			}

			//Czy na polu znajduje siê flaga


			if (board[idx][idy].isRevealed == 0) {
				std::cout << '.';
			}
			else {
				std::cout << 'o';
			}

			//Czy pole zosta³o ods³oniête


			if (board[idx][idy].hasFlag == 0) {
				std::cout << '.';
			}
			else {
				std::cout << 'f';
			}
			std::cout << ')';
		}
		std::cout << std::endl;
	}
}

int MinesweeperBoard::getBoardWidth() const {
	return MinesweeperBoard::width;
}

int MinesweeperBoard::getBoardHeight() const {
	return MinesweeperBoard::height;
}

double MinesweeperBoard::getMineCount() const {
	int mineCount = 0;

	if (mode == EASY) {
		mineCount = width * height * 0.1;
	}
	else if (mode == NORMAL) {
		mineCount = width * height * 0.2;
	}
	else if (mode == HARD) {
		mineCount = width * height * 0.3;
	}
	else if (mode == DEBUG) {
		int diag = 0;
		for (int idx = 0; idx <= (width - 1); idx++) {
			for (int idy = 0; idy <= (height - 1); idy++) {
				if (idx == idy) {
					diag++;
				}
			}
		}
		mineCount = width + ((float)height / 2) + diag - 2;
	}
	return mineCount;
}

int MinesweeperBoard::countMines(int x, int y) const {
	if (board[x][y].isRevealed == 0) {
		return -1;
	}
	else if (x < 0 || x > width || y < 0 || y > height) {
		return -1;
	}
	else {
		int mines = 0;
		if (board[x - 1][y - 1].hasMine == 1 && isInBoard(x - 1, y - 1) == 1) {
			mines++;
		}
		if (board[x][y - 1].hasMine == 1 && isInBoard(x, y - 1) == 1) {
			mines++;
		}
		if (board[x + 1][y - 1].hasMine == 1 && isInBoard(x + 1, y - 1) == 1) {
			mines++;
		}
		if (board[x - 1][y].hasMine == 1 && isInBoard(x - 1, y) == 1) {
			mines++;
		}
		if (board[x + 1][y].hasMine == 1 && isInBoard(x + 1, y) == 1) {
			mines++;
		}
		if (board[x - 1][y + 1].hasMine == 1 && isInBoard(x - 1, y + 1) == 1) {
			mines++;
		}
		if (board[x][y + 1].hasMine == 1 && isInBoard(x, y + 1) == 1) {
			mines++;
		}
		if (board[x + 1][y + 1].hasMine == 1 && isInBoard(x + 1, y + 1) == 1) {
			mines++;
		}
		return mines;
	}

}

bool MinesweeperBoard::hasFlag(int x, int y) const {

	if (x < 0 || x > width || y < 0 || y > height || board[x][y].isRevealed == 1 || board[x][y].hasFlag == 0) {
		return false;
	}
	else {
		return true;
	}
}

void MinesweeperBoard::toggleFlag(int x, int y) {
	if (board[x][y].isRevealed == 1 || x < 0 || x > width || y < 0 || y > height || state == FINISHED_LOSS ||
		state == FINISHED_WIN) {

	}
	else if (board[x][y].hasFlag == 1) {
		board[x][y].hasFlag = false;
	}
	else if (board[x][y].hasFlag == 0) {
		board[x][y].hasFlag = true;
	}
}

void MinesweeperBoard::revealField(int x, int y) {
	if ((board[x][y].isRevealed == 1) | (x < 0) | (x > width) | (y < 0) | (y > height) | (board[x][y].hasFlag == 1) |
		(state == FINISHED_LOSS) | (state == FINISHED_WIN)) {

	}
	else if (board[x][y].hasMine == 0) {
		board[x][y].isRevealed = true;
		revealIfBlank(x, y);
	}
	else if (board[x][y].hasMine == 1) {
		bool firstMove;
		firstMove = true;

		for (int idx = 0; idx <= (width - 1); idx++) {
			for (int idy = 0; idy <= (height - 1); idy++) {
				if (board[idx][idy].isRevealed == 1) {
					firstMove = false;
					break;
				}
			}

			if (!firstMove) {
				break;
			}

		}

		if (!firstMove) {
			board[x][y].isRevealed = true;
			revealIfBlank(x, y);
		}
		else if (firstMove == true) {
			if (mode == DEBUG) {
				board[x][y].isRevealed = true;
				revealIfBlank(x, y);
			}
			else {
				board[x][y].hasMine = false;
				int idx;
				int idy;

				for (;;) {
					idx = rand() % (width - 1);
					idy = rand() % (height - 1);

					if (board[idx][idy].hasMine == 0 && (idx != x || idy != y)) {
						board[idx][idy].hasMine = true;
						break;
					}
				}

				board[x][y].isRevealed = true;
				revealIfBlank(x, y);
			}
		}
	}

}

bool MinesweeperBoard::isRevealed(int x, int y) const {
	if (board[x][y].isRevealed == true) {
		return true;
	}
	else {
		return false;
	}
}

bool MinesweeperBoard::hasMine(int x, int y) const {
	if (board[x][y].hasMine == true) {
		return true;
	}
	else {
		return false;
	}
}

GameState MinesweeperBoard::getGameState() const {
	GameState state = RUNNING;
	for (int idx = 0; idx <= (width - 1); idx++) {
		for (int idy = 0; idy <= (height - 1); idy++) {
			if (board[idx][idy].isRevealed == 1 && board[idx][idy].hasMine == 1) {
				state = FINISHED_LOSS;
				return state;
			}
		}
	}

	int counter = 0;
	for (int idx = 0; idx <= (width - 1); idx++) {
		for (int idy = 0; idy <= (height - 1); idy++) {
			if ((board[idx][idy].hasMine == 1 && board[idx][idy].hasFlag == 1)) {
				counter++;
			
				if (counter == getMineCount()) {
				state = FINISHED_WIN;
				return state;
				}
			}
		}
	}

	int licznik = getMineCount();
	for (int idx = 0; idx <= (width - 1); idx++) {
		for (int idy = 0; idy <= (height - 1); idy++) {
			if ((board[idx][idy].isRevealed == 1 && board[idx][idy].hasMine == 0) ||
				(board[idx][idy].hasMine == 1 && board[idx][idy].hasFlag == 1)) {
				licznik++;

				if (licznik == getBoardWidth() * getBoardHeight()) {
					state = FINISHED_WIN;
					return state;
				}

			}
			
		}
	}
	

	return state;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const {
	if (0 > x || x > width - 1 || 0 > y || y > height - 1) {
		return '#';
	}
	else if (board[x][y].isRevealed == 0 && board[x][y].hasFlag == 1) {
		return 'F';
	}
	else if (board[x][y].isRevealed == 0 && board[x][y].hasFlag == 0) {
		return '_';
	}
	else if (board[x][y].isRevealed == 1 && board[x][y].hasMine == 1) {
		return 'x';
	}
	else if (board[x][y].isRevealed == 1 && countMines(x, y) == 0) {
		return ' ';
	}
	else if (board[x][y].isRevealed == 1 && countMines(x, y) != 0) {
		if (countMines(x, y) == 1) {
			return '1';
		}
		else if (countMines(x, y) == 2) {
			return '2';
		}
		else if (countMines(x, y) == 3) {
			return '3';
		}
		else if (countMines(x, y) == 4) {
			return '4';
		}
		else if (countMines(x, y) == 5) {
			return '5';
		}
		else if (countMines(x, y) == 6) {
			return '6';
		}
		else if (countMines(x, y) == 7) {
			return '7';
		}
		else if (countMines(x, y) == 8) {
			return '8';
		}

	}
	abort();
}

bool MinesweeperBoard::isInBoard(int x, int y) const {
	if (x < 0 || y < 0 || x >= width || y >= height) {
		return false;
	}
	return true;
}

void MinesweeperBoard::revealIfBlank(int x, int y) {
	if (getFieldInfo(x, y) == ' ') {
		if (isInBoard(x - 1, y - 1) && isRevealed(x - 1, y - 1) == 0) {
			revealField(x - 1, y - 1);
			revealIfBlank(x - 1, y - 1);
		}
		if (isInBoard(x, y - 1) && isRevealed(x, y - 1) == 0) {
			revealField(x, y - 1);
			revealIfBlank(x, y - 1);
		}
		if (isInBoard(x + 1, y - 1) && isRevealed(x + 1, y - 1) == 0) {
			revealField(x + 1, y - 1);
			revealIfBlank(x + 1, y - 1);
		}
		if (isInBoard(x - 1, y) && isRevealed(x - 1, y) == 0) {
			revealField(x - 1, y);
			revealIfBlank(x - 1, y);
		}
		if (isInBoard(x + 1, y) && isRevealed(x + 1, y) == 0) {
			revealField(x + 1, y);
			revealIfBlank(x + 1, y);
		}
		if (isInBoard(x - 1, y + 1) && isRevealed(x - 1, y + 1) == 0) {
			revealField(x - 1, y + 1);
			revealIfBlank(x - 1, y + 1);
		}
		if (isInBoard(x, y + 1) && isRevealed(x, y + 1) == 0) {
			revealField(x, y + 1);
			revealIfBlank(x, y + 1);
		}
		if (isInBoard(x + 1, y + 1) && isRevealed(x + 1, y + 1) == 0) {
			revealField(x + 1, y + 1);
			revealIfBlank(x + 1, y + 1);
		}

	}
}

GameMode MinesweeperBoard::getGameMode() const {
	return mode;
}