#include <iostream>;
using namespace std;

const int MAX = 1000;

int input() {
	int size;
	do {
		cout << "Please enter a size of array (1-1000):";
		cin >> size;
	} while (!(size > 0 && size <= MAX));
	return size;
}

void random(int* numbers, int size) {
	for (int i = 0; i < size; i++)
		numbers[i] = rand() % 60 - 20;
}

void ex(int &number1, int &number2) {
	int t = number1;
	number1 = number2;
	number2 = t;
}

void described(int* numbers, int size, int &comparisons, int &exchange) {
	for (int a = 0; a < size - 1; a++) {
		int min = a;
		int b;
		for (b = a + 1; b < size; b++) {
			if (numbers[min] > numbers[b]) {
				min = b;
			}
			comparisons++;
		}
		if (a != min) {

			ex(numbers[a], numbers[min]);
			exchange++;
		}
	}
}

void output(int numbers[], int size, int comparisons, int exchange) {
	for (int i = 0; i < size; i++)
		cout << numbers[i] << "\t";
	cout << "\n";
	cout << "comparisons:" << comparisons << "\n";
	cout << "exchange:" << exchange << "\n";
}

void main() {
	srand(NULL);
	int size = input();
	int comparisons = 0;
	int exchange = 0;
	int numbers[MAX];

	random(numbers, size);
	described(numbers, size, comparisons, exchange);
	output(numbers, size, comparisons, exchange);
	system("pause");
}