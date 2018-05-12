#include <iostream>
#include <string>
using namespace std;

int main() {
	int *p1, *p2;
	int x = 36;
	int y = 67;

	p1 = &x;
	p2 = p1;
	*p1 = 42;
	cout << "*p1:= " << *p1 << '\n';
	cout << "*p2:=" << *p2 << '\n';

	*p2 = 53;
	cout << "*p1:= " << *p1 << '\n';
	cout << "*p2:=" << *p2 << '\n';

	p1 = &y;
	*p1 = 88;
	cout << "*p1:= " << *p1 << '\n';
	cout << "*p2:=" << *p2 << '\n';

	system("pause");
}