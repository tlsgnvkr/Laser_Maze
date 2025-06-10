#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

vector<vector<int>> board(31, vector<int>(31, -1));
vector<int> remenant;
vector<int> X(25, -1);
vector<int> Y(25, -1);
vector<int> Z(25, 0);
int L;

vector<vector<vector<int>>> pointer = {
	{
		{1, 0, 0, 0, 1},
		{0, 2, 2, 2, 0},
		{0, 2, 2, 2, 2},
		{0, 2, 2, 2, 0},
		{1, 0, 0, 0, 1}
	},
	{
		{1, 0, 2, 0, 1},
		{0, 2, 2, 2, 0},
		{0, 2, 2, 2, 0},
		{0, 2, 2, 2, 0},
		{1, 0, 0, 0, 1}
	},
	{
		{1, 0, 0, 0, 1},
		{0, 2, 2, 2, 0},
		{2, 2, 2, 2, 0},
		{0, 2, 2, 2, 0},
		{1, 0, 0, 0, 1}
	},
	{
		{1, 0, 0, 0, 1},
		{0, 2, 2, 2, 0},
		{0, 2, 2, 2, 0},
		{0, 2, 2, 2, 0},
		{1, 0, 2, 0, 1}
	}
};

vector<vector<vector<int>>> target = {
	{
		{1, 3, 0, 3, 1},
		{3, 0, 0, 3, 11},
		{0, 0, 3, 3, 11},
		{3, 3, 3, 0, 11},
		{1, 0, 0, 0, 1}
	},
	{
		{1, 11, 11, 11, 1},
		{3, 3, 3, 0, 0},
		{0, 0, 3, 3, 0},
		{3, 0, 0, 3, 0},
		{1, 3, 0, 3, 1}
	},
	{
		{1, 0, 0, 0, 1},
		{11, 0, 3, 3, 3},
		{11, 3, 3, 0, 0},
		{11, 3, 0, 0, 3},
		{1, 3, 0, 3, 1}
	},
	{
		{1, 3, 0, 3, 1},
		{0, 3, 0, 0, 3},
		{0, 3, 3, 0, 0},
		{0, 0, 3, 3, 3},
		{1, 11, 11, 11, 1}
	}
};

vector<vector<vector<int>>> mirror = {
	{
		{1, 4, 0, 4, 1},
		{4, 0, 0, 4, 4},
		{0, 0, 4, 0, 0},
		{4, 4, 0, 0, 4},
		{1, 4, 0, 4, 1}
	},
	{
		{1, 4, 0, 4, 1},
		{4, 4, 0, 0, 4},
		{0, 0, 4, 0, 0},
		{4, 0, 0, 4, 4},
		{1, 4, 0, 4, 1}
	},
	{
		{1, 4, 0, 4, 1},
		{4, 0, 0, 4, 4},
		{0, 0, 4, 0, 0},
		{4, 4, 0, 0, 4},
		{1, 4, 0, 4, 1}
	},
	{
		{1, 4, 0, 4, 1},
		{4, 4, 0, 0, 4},
		{0, 0, 4, 0, 0},
		{4, 0, 0, 4, 4},
		{1, 4, 0, 4, 1}
	}
};

vector<vector<vector<int>>> spliter = {
	{
		{1, 5, 0, 5, 1},
		{5, 0, 6, 5, 5},
		{0, 6, 5, 6, 0},
		{5, 5, 6, 0, 5},
		{1, 5, 0, 5, 1}
	},
	{
		{1, 5, 0, 5, 1},
		{5, 5, 6, 0, 5},
		{0, 6, 5, 6, 0},
		{5, 0, 6, 5, 5},
		{1, 5, 0, 5, 1}
	},
	{
		{1, 5, 0, 5, 1},
		{5, 0, 6, 5, 5},
		{0, 6, 5, 6, 0},
		{5, 5, 6, 0, 5},
		{1, 5, 0, 5, 1}
	},
	{
		{1, 5, 0, 5, 1},
		{5, 5, 6, 0, 5},
		{0, 6, 5, 6, 0},
		{5, 0, 6, 5, 5},
		{1, 5, 0, 5, 1}
	}
};

vector<vector<vector<int>>> checkpoint = {
	{
		{1, 0, 0, 0, 1},
		{7, 7, 7, 7, 7},
		{0, 0, 8, 0, 0},
		{7, 7, 7, 7, 7},
		{1, 0, 0, 0, 1}
	},
	{
		{1, 7, 0, 7, 1},
		{0, 7, 0, 7, 0},
		{0, 7, 8, 7, 0},
		{0, 7, 0, 7, 0},
		{1, 7, 0, 7, 1}
	},
	{
		{1, 0, 0, 0, 1},
		{7, 7, 7, 7, 7},
		{0, 0, 8, 0, 0},
		{7, 7, 7, 7, 7},
		{1, 0, 0, 0, 1}
	},
	{
		{1, 7, 0, 7, 1},
		{0, 7, 0, 7, 0},
		{0, 7, 8, 7, 0},
		{0, 7, 0, 7, 0},
		{1, 7, 0, 7, 1}
	}
};

vector<vector<int>> stone = {
	{9, 9, 9, 9, 9},
	{9, 9, 9, 9, 9},
	{9, 9, 9, 9, 9},
	{9, 9, 9, 9, 9},
	{9, 9, 9, 9, 9}
};

#define RED 12
#define GREEN 10
#define BLUE 9
#define YELLOW 6
#define CYAN 11
#define MAGENTA 13
#define WHITE 15
#define BLACK 0
#define LIGHTGREY 7
#define DARKGREY 8
#define LEFT 97
#define RIGHT 100
#define UP 119
#define DOWN 115
#define Q 113
#define E 101
#define SPACE 32
#define RESET 114
#define ZZ 122

void textColor(int, int);
void boardCreate(int);
void boardSet(int);
void laserProgress(int, int, int);
void printBoard(int, int, int);
int left(int);
int right(int);
int up(int);
int down(int);
void rotateQ(int, int, int);
void rotateE(int, int, int);
void boardPutin(int, int, int, int);
void boardReset(int);
int boardCheck(int);
void gameOver_positive();
void gameOver_negative();

void textColor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void boardCreate(int N) {
	int K;

	for (int i = 0; i < 25; i += 1) {
		X[i] = -1;
	}

	L = rand() % 25;
	X[L] = rand() % 4 + 100;

	int a = 0;
	if (N == 1) a = 1 + rand() % 2;
	else if (N == 2) a = 1 + rand() % 3;
	else if (N == 3) a = 1 + rand() % 4;

	for (int i = 0; i < a; i += 1) {
		while (1) {
			K = rand() % 25;
			if (X[K] == -1) break;
		}
		X[K] = rand() % 4 + 4 + 100;

		if (rand() % 10 == 0) X[K] += 100;
	}

	if (rand() % 2) {
		while (1) {
			K = rand() % 25;
			if (X[K] == -1) break;
		}
		X[K] = rand() % 4 + 8 + 100;

		if (rand() % 4 == 0) X[K] += 100;
	}

	for (int i = 0; i < N - 1; i += 1) {
		if (rand() % 3 == 0) {
			while (1) {
				K = rand() % 25;
				if (K != 0 && K != 4 && K != 20 && K != 24) {
					if (X[K] == -1) break;
				}
			}
			X[K] = rand() % 4 + 12 + 100;

			if (rand() % 4 == 0) X[K] += 100;
		}
	}

	if (rand() % 2) {
		while (1) {
			K = rand() % 25;
			if (K != 0 && K != 4 && K != 20 && K != 24) {
				if (X[K] == -1) break;
			}
		}
		X[K] = rand() % 4 + 16 + 100;

		if (rand() % 4 == 0) X[K] += 100;
	}

	if (rand() % 2) {
		while (1) {
			K = rand() % 25;
			if (X[K] == -1) break;
		}
		X[K] = 120;
	}

	boardSet(N);
}

void boardSet(int N) {
	for (int y = 0; y < 5; y += 1) {
		for (int x = 0; x < 5; x += 1) {
			for (int i = y * 6 + 1; i < (y + 1) * 6; i += 1) {
				for (int j = x * 6 + 1; j < (x + 1) * 6; j += 1) {
					int N = y * 5 + x;
					int Z;
					if (X[N] == -1) {
						board[i][j] = 0;
					}
					else if ((X[N] % 100) / 4 == 0) {
						Z = (X[N] % 100) % 4;
						board[i][j] = pointer[Z][i % 6 - 1][j % 6 - 1];
						if (X[N] >= 200) board[i][j] += 200;
						else if (X[N] >= 100) board[i][j] += 100;
					}
					else if ((X[N] % 100) / 4 == 1) {
						Z = (X[N] % 100) % 4;
						board[i][j] = target[Z][i % 6 - 1][j % 6 - 1];
						if (X[N] >= 200) board[i][j] += 200;
						else if (X[N] >= 100) board[i][j] += 100;
					}
					else if ((X[N] % 100) / 4 == 2) {
						Z = (X[N] % 100) % 4;
						board[i][j] = mirror[Z][i % 6 - 1][j % 6 - 1];
						if (X[N] >= 200) board[i][j] += 200;
						else if (X[N] >= 100) board[i][j] += 100;
					}
					else if ((X[N] % 100) / 4 == 3) {
						Z = (X[N] % 100) % 4;
						board[i][j] = spliter[Z][i % 6 - 1][j % 6 - 1];
						if (X[N] >= 200) board[i][j] += 200;
						else if (X[N] >= 100) board[i][j] += 100;
					}
					else if ((X[N] % 100) / 4 == 4) {
						Z = (X[N] % 100) % 4;
						board[i][j] = checkpoint[Z][i % 6 - 1][j % 6 - 1];
						if (X[N] >= 200) board[i][j] += 200;
						else if (X[N] >= 100) board[i][j] += 100;
					}
					else if ((X[N] % 100) / 4 == 5) {
						board[i][j] = stone[i % 6 - 1][j % 6 - 1];
					}
				}
			}
		}
	}

	vector<int> Y = { 1, 5, 1, N - 1, 1, 1 };

	for (int i = 0; i < 25; i += 1) {
		if (X[i] != -1) {
			Y[(X[i] % 100) / 4] -= 1;
		}
	}

	Y[4] = 0;
	Y[5] = 0;

	remenant.clear();

	for (int i = 0; i < 31; i += 1) {
		for (int j = 0; j < 31; j += 1) {
			if (!(i % 6) || !(j % 6)) {
				board[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < Y[i]; j += 1) {
			remenant.push_back(i);
		}
	}

	for (int i = 0; i < 25; i += 1) {
		Z[i] = 0;
	}

	int y = (L / 5) * 6;
	int x = (L % 5) * 6;
	int c = 0;

	Z[L] = 1;

	if (board[y + 1][x + 3] % 100 == 2) {
		y = y;
		x = x + 3;
		c = 1;
	}
	else if (board[y + 5][x + 3] % 100 == 2) {
		y = y + 6;
		x = x + 3;
		c = 3;
	}
	else if (board[y + 3][x + 1] % 100 == 2) {
		y = y + 3;
		x = x;
		c = 2;
	}
	else if (board[y + 3][x + 5] % 100 == 2) {
		y = y + 3;
		x = x + 6;
		c = 0;
	}

	laserProgress(y, x, c);
}

void laserProgress(int y, int x, int c) {
	int a, b;
	board[y][x] = board[y][x] - board[y][x] % 100 + 2;

	if ((y % 6 == 3 && x % 6 == 3) || (abs(y % 6 - 3) == 1 && abs(x % 6 - 3) == 1)) {
		int P = (y / 6) * 5 + (x / 6);
		if (X[P] != -1) Z[P] = 1;
	}

	if (x == 0 || x == 30 || y == 0 || y == 30) {
		return;
	}

	if (c == 0) {
		if (board[y][x + 1] % 100 == 3 || board[y][x + 1] % 100 == 4 || board[y][x + 1] % 100 == 5) {
			int k = 0;
			if (board[y - 1][x] % 100 == 0) {
				k -= 1;
			}
			if (board[y + 1][x] % 100 == 0) {
				k += 1;
			}

			if (k == -1) {
				laserProgress(y - 1, x, 1);
			}
			else if (k == 1) {
				laserProgress(y + 1, x, 3);
			}
			else if (k == 0) return;
		}
		else if (board[y][x + 1] % 100 == 6) {
			board[y][x + 1] = board[y][x + 1] - board[y][x + 1] % 100 + 2;
			board[y][x + 2] = board[y][x + 2] - board[y][x + 2] % 100 + 2;

			if (board[y - 1][x + 1] % 100 == 0) {
				board[y - 1][x + 1] = board[y - 1][x + 1] - board[y - 1][x + 1] % 100 + 2;
				board[y - 1][x + 2] = board[y - 1][x + 2] - board[y - 1][x + 2] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y - 2, x + 2, 1);
			}
			else if (board[y + 1][x + 1] % 100 == 0) {
				board[y + 1][x + 1] = board[y + 1][x + 1] - board[y + 1][x + 1] % 100 + 2;
				board[y + 1][x + 2] = board[y + 1][x + 2] - board[y + 1][x + 2] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y + 2, x + 2, 3);
			}
			laserProgress(y, x + 3, 0);
		}
		else if (board[y][x + 1] % 100 == 7) return;
		else if (board[y][x + 1] % 100 == 8) {
			board[y][x + 1] += 2;
			int P = (y / 6) * 5 + (x / 6);
			Z[P] = 1;
			laserProgress(y, x + 2, 0);
		}
		else if (board[y][x + 1] % 100 == 11) {
			board[y][x + 1] += 1000;
			board[y - 1][x + 1] += 1000;
			board[y + 1][x + 1] += 1000;

			a = y / 6;
			b = x / 6;
			Z[a * 5 + b] = 1;

			return;
		}
		else laserProgress(y, x + 1, 0);
	}
	else if (c == 1) {
		if (board[y - 1][x] % 100 == 3 || board[y - 1][x] % 100 == 4 || board[y - 1][x] % 100 == 5) {
			int k = 0;
			if (board[y][x - 1] % 100 == 0) {
				k -= 1;
			}
			if (board[y][x + 1] % 100 == 0) {
				k += 1;
			}

			if (k == -1) {
				laserProgress(y, x - 1, 2);
			}
			else if (k == 1) {
				laserProgress(y, x + 1, 0);
			}
			else if (k == 0) return;
		}
		else if (board[y - 1][x] % 100 == 6) {
			board[y - 1][x] = board[y - 1][x] - board[y - 1][x] % 100 + 2;
			board[y - 2][x] = board[y - 2][x] - board[y - 2][x] % 100 + 2;

			if (board[y - 1][x - 1] % 100 == 0) {
				board[y - 1][x - 1] = board[y - 1][x - 1] - board[y - 1][x - 1] % 100 + 2;
				board[y - 2][x - 1] = board[y - 2][x - 1] - board[y - 2][x - 1] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y - 2, x - 2, 2);
			}
			else if (board[y - 1][x + 1] % 100 == 0) {
				board[y - 1][x + 1] = board[y - 1][x + 1] - board[y - 1][x + 1] % 100 + 2;
				board[y - 2][x + 1] = board[y - 2][x + 1] - board[y - 2][x + 1] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y - 2, x + 2, 0);
			}
			laserProgress(y - 3, x, 1);
		}
		else if (board[y - 1][x] % 100 == 7) return;
		else if (board[y - 1][x] % 100 == 8) {
			board[y - 1][x] += 2;
			int P = (y / 6) * 5 + (x / 6);
			Z[P] = 1;
			laserProgress(y - 2, x, 1);
		}
		else if (board[y - 1][x] % 100 == 11) {
			board[y - 1][x] += 1000;
			board[y - 1][x - 1] += 1000;
			board[y - 1][x + 1] += 1000;

			a = y / 6 - 1;
			b = x / 6;
			Z[a * 5 + b] = 1;

			return;
		}
		else laserProgress(y - 1, x, 1);
	}
	else if (c == 2) {
		if (board[y][x - 1] % 100 == 3 || board[y][x - 1] % 100 == 4 || board[y][x - 1] % 100 == 5) {
			int k = 0;
			if (board[y - 1][x] % 100 == 0) {
				k -= 1;
			}
			if (board[y + 1][x] % 100 == 0) {
				k += 1;
			}

			if (k == -1) {
				laserProgress(y - 1, x, 1);
			}
			else if (k == 1) {
				laserProgress(y + 1, x, 3);
			}
			else if (k == 0) return;
		}
		else if (board[y][x - 1] % 100 == 6) {
			board[y][x - 1] = board[y][x - 1] - board[y][x - 1] % 100 + 2;
			board[y][x - 2] = board[y][x - 2] - board[y][x - 2] % 100 + 2;

			if (board[y - 1][x - 1] % 100 == 0) {
				board[y - 1][x - 1] = board[y - 1][x - 1] - board[y - 1][x - 1] % 100 + 2;
				board[y - 1][x - 2] = board[y - 1][x - 2] - board[y - 1][x - 2] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y - 2, x - 2, 1);
			}
			else if (board[y + 1][x - 1] % 100 == 0) {
				board[y + 1][x - 1] = board[y + 1][x - 1] - board[y + 1][x - 1] % 100 + 2;
				board[y + 1][x - 2] = board[y + 1][x - 2] - board[y + 1][x - 2] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y + 2, x - 2, 3);
			}
			laserProgress(y, x - 3, 2);
		}
		else if (board[y][x - 1] % 100 == 7) return;
		else if (board[y][x - 1] % 100 == 8) {
			board[y][x - 1] += 2;
			int P = (y / 6) * 5 + (x / 6);
			Z[P] = 1;
			laserProgress(y, x - 2, 2);
		}
		else if (board[y][x - 1] % 100 == 11) {
			board[y][x - 1] += 1000;
			board[y - 1][x - 1] += 1000;
			board[y + 1][x - 1] += 1000;

			a = y / 6;
			b = x / 6 - 1;
			Z[a * 5 + b] = 1;

			return;
		}
		else laserProgress(y, x - 1, 2);
	}
	else if (c == 3) {
		if (board[y + 1][x] % 100 == 3 || board[y + 1][x] % 100 == 4 || board[y + 1][x] % 100 == 5) {
			int k = 0;
			if (board[y][x - 1] % 100 == 0) {
				k -= 1;
			}
			if (board[y][x + 1] % 100 == 0) {
				k += 1;
			}

			if (k == -1) {
				laserProgress(y, x - 1, 2);
			}
			else if (k == 1) {
				laserProgress(y, x + 1, 0);
			}
			else if (k == 0) return;
		}
		else if (board[y + 1][x] % 100 == 6) {
			board[y + 1][x] = board[y + 1][x] - board[y + 1][x] % 100 + 2;
			board[y + 2][x] = board[y + 2][x] - board[y + 2][x] % 100 + 2;

			if (board[y + 1][x - 1] % 100 == 0) {
				board[y + 1][x - 1] = board[y + 1][x - 1] - board[y + 1][x - 1] % 100 + 2;
				board[y + 2][x - 1] = board[y + 2][x - 1] - board[y + 2][x - 1] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y + 2, x - 2, 2);
			}
			else if (board[y + 1][x + 1] % 100 == 0) {
				board[y + 1][x + 1] = board[y + 1][x + 1] - board[y + 1][x + 1] % 100 + 2;
				board[y + 2][x + 1] = board[y + 2][x + 1] - board[y + 2][x + 1] % 100 + 2;
				int P = (y / 6) * 5 + (x / 6);
				Z[P] = 1;
				laserProgress(y + 2, x + 2, 0);
			}
			laserProgress(y + 3, x, 3);
		}
		else if (board[y + 1][x] % 100 == 7) return;
		else if (board[y + 1][x] % 100 == 8) {
			board[y + 1][x] += 2;
			int P = (y / 6) * 5 + (x / 6);
			Z[P] = 1;
			laserProgress(y + 2, x, 3);
		}
		else if (board[y + 1][x] % 100 == 11) {
			board[y + 1][x] += 1000;
			board[y + 1][x - 1] += 1000;
			board[y + 1][x + 1] += 1000;

			a = y / 6;
			b = x / 6;
			Z[a * 5 + b] = 1;

			return;
		}
		else laserProgress(y + 1, x, 3);
	}
}

void printBoard(int y, int x, int rex) {
	system("cls");
	for (int i = 0; i < 31; i += 1) {
		for (int j = 0; j < 31; j += 1) {
			textColor(WHITE, BLACK);
			if (board[i][j] % 100 == 2 || board[i][j] % 100 == 10) {
				textColor(WHITE, RED);
				if (j % 6 == 0) cout << " ";
				else cout << "  ";
			}
			else if (i == 0 && j == 0) cout << "┌";
			else if (i == 0 && j == 30) cout << "┐";
			else if (i == 30 && j == 0) cout << "└";
			else if (i == 30 && j == 30) cout << "┘";
			else if (i == 0 && j % 6 == 0) cout << "┬";
			else if (i == 30 && j % 6 == 0) cout << "┴";
			else if (i % 6 == 0 && j == 0) cout << "├";
			else if (i % 6 == 0 && j == 30) cout << "┤";
			else if (i % 6 == 0 && j % 6 == 0) cout << "┼";
			else if (i % 6 == 0) cout << "──";
			else if (j % 6 == 0) cout << "│";
			else {
				if (board[i][j] == 0 || board[i][j] == 1) {
					textColor(WHITE, BLACK);
				}
				else if (board[i][j] % 100 == 0 || board[i][j] == 101) {
					textColor(WHITE, LIGHTGREY);
				}
				else if (board[i][j] == 201) {
					textColor(WHITE, CYAN);
				}
				else if (board[i][j] % 100 == 3) {
					textColor(WHITE, MAGENTA);
				}
				else if (board[i][j] % 100 == 4) {
					textColor(WHITE, BLUE);
				}
				else if (board[i][j] % 100 == 5) {
					textColor(WHITE, GREEN);
				}
				else if (board[i][j] == 6) {
					textColor(WHITE, BLACK);
				}
				else if (board[i][j] == 106 || board[i][j] == 206) {
					textColor(WHITE, LIGHTGREY);
				}
				else if (board[i][j] % 100 == 7) {
					textColor(WHITE, YELLOW);
				}
				else if (board[i][j] == 8) {
					textColor(WHITE, BLACK);
				}
				else if (board[i][j] == 108 || board[i][j] == 208) {
					textColor(WHITE, LIGHTGREY);
				}
				else if (board[i][j] % 100 == 9) {
					textColor(WHITE, WHITE);
				}
				else if (board[i][j] % 100 == 11) {
					textColor(WHITE, RED);
				}

				if (i / 6 == y && i % 6 != 0 && j / 6 == x && j % 6 != 0) {
					int a = board[i][j] % 100;
					if (a == 0 || a == 1 || a == 6 || a == 8) {
						textColor(WHITE, DARKGREY);
					}
					if (board[i][j] >= 200 && abs(i % 6 - 3) == 2 && abs(j % 6 - 3) == 2) textColor(WHITE, CYAN);
				}
				cout << "  ";
			}
		}
		cout << endl;
	}

	cout << endl << endl << "Remenant :" << endl;
	if (remenant.size()) {
		for (int i = 0; i < remenant.size(); i += 1) {
			if (i == 0) cout << "┌";
			else cout << "┬";
			cout << "──────────";
		}
		cout << "┐" << endl;

		for (int j = 0; j < 3; j += 1) {
			for (int i = 0; i < remenant.size(); i += 1) {
				textColor(WHITE, BLACK);
				cout << "│";

				if (rex == i && j == 2) {
					textColor(WHITE, DARKGREY);
					cout << "          ";
				}
				else {
					if (remenant[i] == 1) {
						textColor(WHITE, MAGENTA);
						cout << "          ";
					}
					else if (remenant[i] == 2) {
						textColor(WHITE, BLUE);
						cout << "          ";
					}
					else if (remenant[i] == 3) {
						textColor(WHITE, GREEN);
						cout << "          ";
					}
				}
			}
			textColor(WHITE, BLACK);
			cout << "│" << endl;
		}

		for (int i = 0; i < remenant.size(); i += 1) {
			if (i == 0) cout << "└";
			else cout << "┴";
			cout << "──────────";
		}
		cout << "┘" << endl;
	}

	cout << "Press \"Z\" key to end the Game." << endl;
}


int left(int x) {
	if (x != 0) x -= 1;
	return x;
}

int right(int x) {
	if (x != 4) x += 1;
	return x;
}

int up(int y) {
	if (y != 0) y -= 1;
	return y;
}

int down(int y) {
	if (y != 4) y += 1;
	return y;
}

void rotateQ(int y, int x, int N) {
	int k = y * 5 + x;
	if (X[k] != -1 && X[k] < 200) {
		X[k] += 1;
		if (X[k] % 4 == 0) {
			X[k] -= 4;
		}
	}

	boardSet(N);
}

void rotateE(int y, int x, int N) {
	int k = y * 5 + x;
	if (X[k] != -1 && X[k] < 200) {
		X[k] -= 1;
		if (X[k] % 4 == 3) {
			X[k] += 4;
		}
	}

	boardSet(N);
}

void boardPutin(int y, int x, int A, int N) {
	int k = y * 5 + x;
	if (X[k] == -1) {
		if (X[k] < 100) X[k] = A;
	}
	else {
		X[k] = -1;
	}
	boardSet(N);
}

void boardReset(int N) {
	int c = 0;
	for (int i = 0; i < 25; i += 1) {
		if (X[i] != -1 && X[i] < 100) {
			X[i] = -1;
			c = 1;
		}
	}
	if (c) {
		boardSet(N);
	}
	else {
		boardCreate(N);
	}
}

int boardCheck(int N) {
	vector<int> P(3, 0);
	for (int i = 0; i < 31; i += 1) {
		for (int j = 0; j < 31; j += 1) {
			if (board[i][j] >= 1000) P[0] += 1;
		}
	}

	for (int i = 0; i < 25; i += 1) {
		if (16 <= X[i] % 100 && X[i] % 100 < 20 && Z[i] == 0) P[1] -= 1;

		if (X[i] != -1 && X[i] != 120 && Z[i] == 0) P[2] -= 1;
	}

	if (P[0] == 3 * N && P[1] == 0 && P[2] == 0) return 1;
	else return 0;
}

void gameOver_positive() {
	cout << endl << endl;

	cout << "Game Over" << endl << "You Win!" << endl;

	system("PAUSE");
}

void gameOver_negative() {
	cout << endl << endl;

	cout << "Game Over" << endl << "You Lose!" << endl;

	system("PAUSE");
}

int main() {
	srand((unsigned int)GetTickCount64());
	int N, y = 0, x = 0, k = 0;
	int pivot = 0;
	int key;
	while (1) {
		cout << "Select Target #: ";
		cin >> N;
		if (1 <= N && N <= 3) {
			boardCreate(N);
			break;
		}
		else cout << "Wrong Response. Please Select number between 1 & 3." << endl;
	}
	printBoard(y, x, -1);

	while (1) {
		key = _getch();
		switch (key) {
		case LEFT:
			if (!pivot) x = left(x);
			else {
				if (k != 0) k -= 1;
			}
			break;

		case RIGHT:
			if (!pivot) x = right(x);
			else {
				if (k != remenant.size() - 1) k += 1;
			}
			break;

		case UP:
			if (!pivot) y = up(y);
			break;

		case DOWN:
			if (!pivot) y = down(y);
			break;

		case Q:
			if (!pivot) rotateQ(y, x, N);
			break;

		case E:
			if (!pivot) rotateE(y, x, N);
			break;

		case SPACE:
			if (remenant.size() != 0) {
				if (!pivot) {
					k = 0;
					if (X[y * 5 + x] == -1) pivot = 1;
					else if (X[y * 5 + x] < 100) boardPutin(y, x, X[y * 5 + x], N);
				}
				else {
					boardPutin(y, x, remenant[k] * 4, N);
					pivot = 0;
				}
			}
			break;

		case RESET:
			if (pivot == 0) {
				boardReset(N);
			}
			break;

		case ZZ: gameOver_negative();
			return 0;
		}

		if (!pivot) printBoard(y, x, -1);
		else printBoard(y, x, k);

		if (boardCheck(N)) {
			gameOver_positive();
			return 0;
		}
	}
}
