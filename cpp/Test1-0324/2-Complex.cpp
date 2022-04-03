#include <iostream>
using namespace std;

class Complex {
public:
    Complex(double r = 0, double i = 0) :real(r), imag(i) {}
    Complex operator+(const Complex&) const;//重载双目运算符'+'
    Complex operator-=(const Complex&); //重载双目运算符'-='
    friend Complex operator-(const Complex&, const Complex&);//重载双目运算符'-'
    void Display() const;
private:
    double real;
    double imag;
};

Complex Complex::operator+(const Complex& c) const {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator-=(const Complex& c) {
    real -= c.real;
    imag -= c.imag;
    return *this;
}

Complex operator-(const Complex& c1, const Complex& c2) {
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}

void Complex::Display() const {
    cout << "(" << real << ", " << imag << ")" << endl;
}

int main() {
    double r, m;
    cin >> r >> m;
    Complex c1(r, m);
    cin >> r >> m;
    Complex c2(r, m);
    Complex c3 = c1 + c2;
    c3.Display();
    c3 = c1 - c2;
    c3.Display();
    c3 -= c1;
    c3.Display();
    return 0;
}
