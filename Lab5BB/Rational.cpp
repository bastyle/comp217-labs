#include "Rational.h"
#include <cmath>

Rational::Rational() : numerator(0.0), denominator(1.0) {}

Rational::Rational(double num, double denom) : numerator(num), denominator(denom) {}

void Rational::Reduce() {
    const double hcf = getHighestCommonFactor(numerator, denominator);
    this->numerator /= hcf;
    this->denominator /= hcf;
}

double Rational::getNumerator() const {
    return numerator;
}

double Rational::getDenominator() const {
    return denominator;
}

Rational Rational::operator+(const Rational& other) const {
    double const newNumerator = numerator * other.denominator + other.numerator * denominator;
    double const newDenominator = denominator * other.denominator;
    Rational result(newNumerator, newDenominator);
    result.Reduce();
    return result;
}

Rational Rational::operator-(const Rational& other) const {
    double const newNumerator = numerator * other.denominator - other.numerator * denominator;
    double const newDenominator = denominator * other.denominator;
    Rational result(newNumerator, newDenominator);
    result.Reduce();
    return result;
}

Rational Rational::operator*(const Rational& other) const {
    double const newNumerator = numerator * other.numerator;
    double const newDenominator = denominator * other.denominator;
    Rational newRational(newNumerator, newDenominator);
    newRational.Reduce();
    return newRational;
}

Rational Rational::operator/(const Rational& other) const {
    double const newNumerator = numerator * other.denominator;
    double const newDenominator = denominator * other.numerator;
    Rational newRational(newNumerator, newDenominator);
    newRational.Reduce();
    return newRational;
}

// Overloaded stream operators
std::istream& operator>>(std::istream& in, Rational& r) {
    double num, denom;
    in >> num >> denom;
    r = Rational(num, denom);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.numerator << "/" << r.denominator;
    return out;
}


// Overloaded relational and equality operators

bool Rational::operator<(const Rational& other) const {
    return this->getCurrentValue() < other.getCurrentValue();
}

bool Rational::operator>(const Rational& other) const {
    return this->getCurrentValue() > other.getCurrentValue();
}

bool Rational::operator<=(const Rational& other) const {
    return this->getCurrentValue() <= other.getCurrentValue();
}

bool Rational::operator>=(const Rational& other) const {
    return this->getCurrentValue() >= other.getCurrentValue();
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator==(const Rational& other) const {
    return this->getCurrentValue() == other.getCurrentValue();
}

double Rational::getCurrentValue() const
{
    return this->getNumerator() / this->getDenominator();
}

// Overloaded increment and decrement operators

Rational& Rational::operator++() {
    // pre-increment operator
    if (denominator == 1) {
        numerator++;
        return *this;
    }
    else {
        // throw an exception if the denominator is not 1
        throw std::invalid_argument("Denominator must be 1 to use pre-increment operator.");
    }
}

Rational& Rational::operator--() {
    // pre-decrement operator
    if (denominator == 1) {
        numerator--;
        return *this;
    }
    else {
        // throw an exception if the denominator is not 1
        throw std::invalid_argument("Denominator must be 1 to use pre-decrement operator.");
    }
}

Rational Rational::operator++(int) {
    // post-increment operator
    if (denominator == 1) {
        Rational temp(*this);
        numerator++;
        return temp;
    }
    else {
        // throw an exception if the denominator is not 1
        throw std::invalid_argument("Denominator must be 1 to use post-increment operator.");
    }
}

Rational Rational::operator--(int) {
    // post-decrement operator
    if (denominator == 1) {
        Rational temp(*this);
        numerator--;
        return temp;
    }
    else {
        // throw an exception if the denominator is not 1
        throw std::invalid_argument("Denominator must be 1 to use post-decrement operator.");
    }
}

double Rational::getHighestCommonFactor(double a, double b) const {
    // Euclidean algorithm to find the getHighestCommonFactor of a and b
    while (b != 0) {
	    const double auxiliar = b;
        b = fmod(a, b);
        a = auxiliar;
    }
    return a;
}
