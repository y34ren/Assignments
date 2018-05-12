#include <iostream>
using namespace std;

float calculation(float amount, float monthly, float interest) {//Calculation every month
	amount += monthly;
	amount += amount*interest;
	return amount;
}

void main() {
	float amount = 0, monthly = 0, interest = 0;
	int time = 0;

	cout << "This is a Savings Calculator system.\n\n"
	//---------------------------------------------------Input Information
		<< "Please enter the following information:\n"
		<< "The initial amount in the account:";
	cin >> amount;
	cout << "The monthly payment:";
	cin >> monthly;
	cout << "A yearly nominal interest rate:";
	cin >> interest;
	cout << "The number of months for which the calculation is performed:";
	cin >> time;
	cout << "\n";
	//---------------------------------------------------Calculation
	interest /= 12;
	for (int i = 0; i < time; i++) {
		amount = calculation(amount, monthly, interest);
	//---------------------------------------------------Output Monthly
		cout << "Month:" << i + 1 << "  \tAccount:" << amount << "\n";
	}
	cout << "\nPress any key";
	system("pause");
}