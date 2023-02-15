#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
    Rational();
    Rational(double num, double denom);

    void Reduce();
    double GetNumerator() const;
    double GetDenominator() const;

    // Overloaded arithmetic operators
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Overloaded stream operators
    friend std::istream& operator>>(std::istream& in, Rational& r);
    friend std::ostream& operator<<(std::ostream& out, const Rational& r);

private:
    double numerator;
    double denominator;

    double HCF(double a, double b);
};

#endif

