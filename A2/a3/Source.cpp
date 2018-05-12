//
//  main.cpp
//  N_Queens
//
//  Created by Yifei Ren on 15/10/22.
//  Student ID: 0315812
//  Copyright ? 2015Äê Yifei Ren. All rights reserved.
//



#include <iostream>
#include <cmath>
using namespace std;

const int MaxSize = 26;
const int MinSize = 4;

int input()
{
	int Size;

	cout << "Enter the size N for your N X N board:" << endl;
	cin >> Size;

	if (Size > MaxSize) {

		Size = MaxSize;

	}

	if (Size < MinSize) {
		Size = MinSize;
	}
	return Size;

}

void initial(int* B, int Size)
{

	for (int i = 0; i < Size; i++)
	{
		B[i] = 0;
	}
}

bool free(int x) {
	return x == 0;
}

void print(int* Solution, int Size) {
	for (int i = 0; i < Size; i++) {
		cout << char(i + 'a') << "," << Solution[i] << "  ";
	}
	cout << "\n";
}

void addQueen(int *B, int Size, int numQueen, int &numSolution, int *Solution) {
	if (numQueen < Size) {

		for (int i = (numQueen*Size); i < (Size + (numQueen*Size)); i++) {
			
			if (free(B[i])) {

				B[i] = 1;
				Solution[i - (numQueen*Size)] = numQueen;
				numQueen++;
				for (int j = 1; j <= (Size - numQueen); j++) {
					//mark culum under queen -1
					B[i + (j* Size)] -= 1;
					//mark Diagonal right as -1
					if (i % Size + j < Size) {
						B[i + (j* Size) + j] -= 1;

					}
					//mark Diagonal left as -1
					if (i % Size - j >= 0) {
						B[i + (j* Size) - j] -= 1;

					}

				}
				addQueen(B, Size, numQueen, numSolution, Solution);

				B[i] = 0;

				Solution[i - (numQueen*Size)] = 0;


				for (int j = 1; j <= (Size - numQueen); j++) {

					//unmark culum under queen +1
					B[i + (j* Size)] += 1;
					//unmark Diagonal right +1
					if (i % Size + j < Size) {
						B[i + (j* Size) + j] += 1;

					}
					//mark Diagonal left as +1
					if (i % Size - j >= 0) {
						B[i + (j* Size) - j] += 1;

					}

				}
				numQueen--;

			}
		}

	}
	else {
		print(Solution, Size);
		numSolution++;
	}

}

void main() {
	int Size = 4;
	int numSolution=0;
	int BoardSize;

	BoardSize = Size * Size;



	int Game_board[16];
	int Solution[4];



	initial(Game_board, BoardSize);
	initial(Solution, Size);

	//print(Solution, Size);


	addQueen(Game_board, Size, 0, numSolution, Solution);

	system("Pause");

}
