#include<stdio.h>
#include<stdbool.h>
#define CHESS_SIZE 8
#define NUM_OF_QUEEN 8
int chess[CHESS_SIZE][CHESS_SIZE];
int solution;

void init() {
	solution = 0;
	for (int i = 0; i < CHESS_SIZE; i++) {
		for (int j = 0; j < CHESS_SIZE; j++) {
			chess[i][j] = 0;//no queen
		}
	}
}
bool chessHave8Queen() {
	int numQueen = 0;
	for (int i = 0; i < CHESS_SIZE; i++) {
		for (int j = 0; j < CHESS_SIZE; j++) {
			if (chess[i][j] == 1)
				numQueen++;
		}
	}
	if (numQueen >= NUM_OF_QUEEN)
		return true;
	return false;
}
void printChess() {
	for (int i = 0; i < CHESS_SIZE; i++) {
		for (int j = 0; j < CHESS_SIZE; j++) {
			printf("%d ",chess[i][j]);
		}
		printf("\n");
	}
}
bool checkRightUp(int i, int j) {

	while (1) {
		i++;
		j++;
		if (i >= CHESS_SIZE || j >= CHESS_SIZE)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool checkRightDown(int i, int j) {

	while (1) {
		i++;
		j--;
		if (i >= CHESS_SIZE || j < 0)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool checkLeftUp(int i, int j) {

	while (1) {
		i--;
		j++;
		if (i < 0 || j >= CHESS_SIZE)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool checkLeftDown(int i, int j) {

	while (1) {
		i--;
		j--;
		if (i < 0 || j < 0)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool checkRight(int i, int j) {

	while (1) {
		i++;
		if (i >= CHESS_SIZE)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool checkLeft(int i, int j) {

	while (1) {
		i--;
		if (i < 0)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool checkUp(int i, int j) {

	while (1) {
		j++;
		if (j >= CHESS_SIZE)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool checkDown(int i, int j) {

	while (1) {
		j--;
		if (j < 0)
			return false;
		if (chess[i][j] == 1)
			return true;
	}
	return false;
}
bool chessViolation() {
	for (int i = 0; i < CHESS_SIZE; i++) {
		for (int j = 0; j < CHESS_SIZE; j++) {
			if (chess[i][j] == 1) {
				if (checkRightUp(i, j)   || checkRight(i, j) ||
					checkRightDown(i, j) || checkLeft(i, j)  ||
					checkLeftUp(i, j)    || checkUp(i, j)    ||
					checkLeftDown(i, j)  || checkDown(i, j))
					return true;
			}
				
		}
	}
	return false;
}

void clearChess(int i,int j) {
	while (1) {
		i++;
		if (i >= CHESS_SIZE) {//自動換行
			j++;
			i = 0;
		}
		if (j >= CHESS_SIZE) {//finish record
			return;
		}
		chess[i][j] = 0;
	}
}
void enumerate8Queen(int currX,int currY) {
	if (currX >= CHESS_SIZE) {//自動換行
		currY++;
		currX = 0;
	}
	if (currY >= CHESS_SIZE) {//finish record
		if (chessHave8Queen() && !chessViolation()) {
			solution++;
			printChess();
		}
		return;
	}	
	//put 0
	chess[currX][currY] = 0;
	enumerate8Queen(currX + 1, currY);
	clearChess(currX, currY);
	//put 1
	chess[currX][currY] = 1;
	if (chessViolation()) {
		return;
	}
	enumerate8Queen(currX + 1, currY);
}
int main() {
	init();
	enumerate8Queen(0,0);
	printf("Number of solution = %d", solution);
}