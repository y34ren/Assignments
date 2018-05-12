#include "Fraction.h"

Fraction::Fraction(long numerator, long denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	Irreducible();
}

void Fraction::setNumerator(long numerator) {
	this->numerator = numerator;
	Irreducible();
}

void Fraction::setDenominator(long denominator) {
	this->denominator = denominator;
	Irreducible();
}

long Fraction::getNumerator()
{
	return this->numerator;
}

long Fraction::getDenominator()
{
	return this->denominator;
}

double Fraction::getDbl() {
	return (double)this->numerator / (double)this->denominator;
}

Fraction Fraction::operator-()const
{
	long x = this->numerator*-1;
	long y = this->denominator;
	Fraction answer(x, y);
	return answer;
}

Fraction Fraction::operator+(const Fraction & b)const
{
	long x = this->numerator*b.denominator + b.numerator*this->denominator;
	long y = this->denominator*b.denominator;
	Fraction answer(x, y);
	return answer;
}

Fraction Fraction::operator-(const Fraction & b)const
{
	long x = this->numerator*b.denominator - b.numerator*this->denominator;
	long y = this->denominator*b.denominator;
	Fraction answer(x, y);
	return answer;
}

Fraction Fraction::operator*(const Fraction & b)const
{
	long x = this->numerator*b.numerator;
	long y = this->denominator*b.denominator;
	Fraction answer(x, y);
	return answer;
}

Fraction Fraction::operator/(const Fraction & b)const
{
	long x = this->numerator*b.denominator;
	long y = this->denominator*b.numerator;
	Fraction answer(x, y);
	return answer;
}

void Fraction::Irreducible() {
	//keep denominator be a positive number
	if (this->denominator < 0) {
		this->numerator *= -1;
		this->denominator *= -1;
	}
	//Irreducible Fraction
	int a = numerator;
	int b = denominator;
	//keep a and b are positive number
	if (a < 0)a *= -1;
	if (b < 0)b *= -1;
	//keep b<a
	if (b > a) {
		int c = a;
		a = b;
		b = c;
	}
	//Simplify
	int g = maxDivisor(a, b);
	numerator /= g;
	denominator /= g;
}

long Fraction::maxDivisor(long a, long b)
{
	//to find Greatest Common Divisor
	if (b == 0)
		return a;
	else
		return maxDivisor(b, a % b);
}
