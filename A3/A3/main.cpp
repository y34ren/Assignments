//  Created by Yifei Ren on 15/10/22.
//  Student ID: 0315812

#include "Fraction.h"
#include <iostream>

using namespace std;

void main() {
	Fraction a(2, 4);
 	Fraction b(5, 20);
	Fraction c(0, 1);

	cout << "a=" << a.getDbl() << " , b=" << b.getDbl() << '\n';
	c = a + b;
	cout << c.getNumerator() << " , " << c.getDenominator() << '\n';
	c = a - b;
	cout << c.getNumerator() << " , " << c.getDenominator() << '\n';
	c = a * b;
	cout << c.getNumerator() << " , " << c.getDenominator() << '\n';
	c = a / b;
	cout << c.getNumerator() << " , " << c.getDenominator() << '\n';
	c = -a;
	cout << c.getNumerator() << " , " << c.getDenominator() << '\n';
	a.setDenominator(-8);
	cout << a.getNumerator() << " , " << a.getDenominator() << '\n';

	system("pause");
}