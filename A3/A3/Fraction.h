#pragma once
class Fraction {
public:
	Fraction(long numerator, long denominator);
	void setNumerator(long numerator);
	void setDenominator(long denominator);
	long getNumerator();
	long getDenominator();
	double getDbl();
	Fraction operator-()const;
	Fraction operator+(const Fraction& b)const;
	Fraction operator-(const Fraction& b)const;
	Fraction operator*(const Fraction& b)const;
	Fraction operator/(const Fraction& b)const;

private:
	long numerator;
	long denominator;
	void Irreducible();
	long maxDivisor(long a, long b);
};