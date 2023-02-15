#include "Rational.h"
#include <cmath>

Rational::Rational() : numerator(0.0), denominator(1.0) {}

Rational::Rational(double num, double denom) : numerator(num), denominator(denom) {}

void Rational::Reduce() {
    double hcf = HCF(numerator, denominator);
    numerator /= hcf;
    denominator /= hcf;
}

double Rational::GetNumerator() const {
    return numerator;
}

double Rational::GetDenominator() const {
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
    double new_numerator = numerator * other.numerator;
    double new_denominator = denominator * other.denominator;
    Rational result(new_numerator, new_denominator);
    result.Reduce();
    return result;
}

Rational Rational::operator/(const Rational& other) const {
    double new_numerator = numerator * other.denominator;
    double new_denominator = denominator * other.numerator;
    Rational result(new_numerator, new_denominator);
    result.Reduce();
    return result;
}

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

double Rational::HCF(double a, double b) {
    // Euclidean algorithm to find the HCF of a and b
    while (b != 0) {
        double temp = b;
        b = fmod(a, b);
        a = temp;
    }
    return a;
}
