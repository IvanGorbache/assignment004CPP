#include "complex.hpp"

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

bool Complex::operator>(const Complex& other) const {
    double mag1 = std::sqrt(real * real + imag * imag);
    double mag2 = std::sqrt(other.real * other.real + other.imag * other.imag);
    return mag1 > mag2;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real << " + " << complex.imag << "i";
    return os;
}

std::string Complex::to_string() const {
    std::stringstream ss;
    ss << real << " + " << imag << "i";
    return ss.str();
}

namespace std {
    std::string to_string(const Complex& complex) {
        return complex.to_string();
    }
}
