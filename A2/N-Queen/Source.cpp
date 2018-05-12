/*
N_Queens
Created by Yifei Ren on 15/10/22.
Student ID: 0315812
*/

#include <iostream>
using namespace std;

//Min and Max size
const int MIN = 4;
const int MAX = 26;

//input size(if the size is not in 4-26, it will be 4).
int input() {
	int n = 0;
	cout << "Please enter the number of N(4-26):";
	cin >> n;
	if (n < 4 && n>26) {//judge if the size is not in 4-26
		cout << "N is out of range. It will be 4." << "\n\n";
		n = 4;
	}
	return n;
}

//output result
void output(int solution[], int count, int n) {
	cout << "solution " << count << "\n";
	for (int i = 0; i < n; i++)
		if (solution[i]>-1)
			cout << char(i + 'a')//change int to char
				<< solution[i] << "\t";
	cout << "\n";
}

//recall function for searching where can place queen(row by row)
void searching(int *board, int *solution, int start, int n, int &count) {
	if (start / MAX < n) {//searching
		for (int i = start; i < start + n; i++) {//loop for row
			if (board[i] == 0) {//judge if there free
				//Mark all
				board[i] = 1;//mark self
				solution[i - start] = start / MAX;//add solution
				for (int j = 1; j < n - start / MAX; j++) {//loop for follow rows
					board[i + j*MAX] += 2;//Mark columns
					if (i - j >= start) board[i + j*MAX - j] += 2;//mark diagonals(left)
					if (i + j < start + n)board[i + j*MAX + j] += 2;//marl diagonals(right)
				}
				searching(board, solution, start + MAX, n, count);//star searching next row
				//Remove mark all
				board[i] = 0;//remove mark self
				solution[i - start] = -1;//remove solution
				for (int j = 1; j < n - start / MAX; j++) {//loop for follow rows
					board[i + j*MAX] -= 2;//Remove Mark columns
					if (i - j >= start) board[i + j*MAX - j] -= 2;//Remove mark diagonals(left)
					if (i + j < start + n)board[i + j*MAX + j] -= 2;//Remove marl diagonals(right)
				}
			}
		}
	}
	else {//stop searching
		//count sum of result
		int c = 0;
		for (int i = 0; i < n; i++)
			if (solution[i] >= 0)c++;
		if (c >= n) output(solution, ++count, n);//output
	}
}

void main() {
	int Board[MAX * MAX];//Board for marking
	int Solution[MAX];//saving Solution
	int N = input();//Board size(nxn)
	int count = 0;//counting number of result

	//Initialization Arrays
	for (int i = 0; i < N; i++) {
		Solution[i] = -1;//Initialization Solution
		for (int j = 0; j < N; j++)
			Board[i*MAX + j] = 0;//Initialization Board
	}

	//star searching
	searching(Board, Solution, 0, N, count);

	system("pause");
}