#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
    Rational();
    Rational(double num, double denom);

    void Reduce();
    double getNumerator() const;
    double getDenominator() const;

    // Overloaded arithmetic operators
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Overloaded stream operators
    friend std::istream& operator>>(std::istream& in, Rational& r);
    friend std::ostream& operator<<(std::ostream& out, const Rational& r);

    // Overloaded relational and equality operators
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator==(const Rational& other) const;

    // Overloaded increment and decrement operators
	Rational & operator++();         // pre-increment
    Rational& operator--();         // pre-decrement
    Rational operator++(int);       // post-increment
    Rational operator--(int);       // post-decrement

    double getCurrentValue() const;

private:
    double numerator;
    double denominator;

    double getHighestCommonFactor(double a, double b) const;
};

#endif

