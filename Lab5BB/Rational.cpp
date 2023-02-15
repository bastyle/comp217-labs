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
    double new_numerator = numerator * other.denominator + other.numerator * denominator;
    double new_denominator = denominator * other.denominator;
    Rational result(new_numerator, new_denominator);
    result.Reduce();
    return result;
}

Rational Rational::operator-(const Rational& other) const {
    double new_numerator = numerator * other.denominator - other.numerator * denominator;
    double new_denominator = denominator * other.denominator;
    Rational result(new_numerator, new_denominator);
    result.Reduce();
    return result;
}

Rational Rational::operator*(const Rational& other) const {
    double newNumerator = numerator * other.numerator;
    double newDenominator = denominator * other.denominator;
    Rational newRational(newNumerator, newDenominator);
    newRational.Reduce();
    return newRational;
}

Rational Rational::operator/(const Rational& other) const {
    double newNumerator = numerator * other.denominator;
    double newDenominator = denominator * other.numerator;
    Rational newRational(newNumerator, newDenominator);
    newRational.Reduce();
    return newRational;
}

std::istream& operator>>(std::istream& in, Rational& r) {
    double num, denom;
    in >> num >> denom;
    r = Rational(num, denom);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.numerator << "/" << r.denominator;
    /*out << r.numerator << "\n";
    out << "--" << "\n";
    out << r.denominator;*/
    return out;
}

double Rational::getHighestCommonFactor(double a, double b) const {
    // Euclidean algorithm to find the getHighestCommonFactor of a and b
    while (b != 0) {
        double temp = b;
        b = fmod(a, b);
        a = temp;
    }
    return a;
}

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
