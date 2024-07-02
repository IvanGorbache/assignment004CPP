#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <sstream> 

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i);
    double get_real() const;
    double get_imag() const;
    bool operator>(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
    std::string to_string() const;

    
};

#endif 

