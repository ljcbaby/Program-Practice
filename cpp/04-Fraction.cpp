#include <cstdio>
#include <iostream>
#include <numeric>

// Fraction in integers of integers
class Fraction {
    int numerator;
    int denominator;
    void simplify();
public:
    Fraction(int, int);
    void set(int, int);
    double toDouble() const;

    // operators

    Fraction operator+(const int&) const;
    Fraction operator+(const Fraction&) const;
    friend Fraction operator+(const int&, const Fraction&);
    Fraction operator-(const int&) const;
    Fraction operator-(const Fraction&) const;
    friend Fraction operator-(const int&, const Fraction&);
    Fraction operator*(const int&) const;
    Fraction operator*(const Fraction&) const;
    friend Fraction operator*(const int&, const Fraction&);
    Fraction operator/(const int&) const;
    Fraction operator/(const Fraction&) const;
    friend Fraction operator/(const int&, const Fraction&);
    Fraction& operator++();
    Fraction& operator++(int);
    Fraction& operator--();
    Fraction& operator--(int);
    Fraction& operator+=(const int&);
    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const int&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator*=(const int&);
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const int&);
    Fraction& operator/=(const Fraction&);
    Fraction& operator=(const int&);
    Fraction& operator=(const Fraction&);

    // comparison operators

    bool operator==(const Fraction&) const;
    bool operator!=(const Fraction&) const;
    bool operator<(const Fraction&) const;
    bool operator>(const Fraction&) const;
    bool operator<=(const Fraction&) const;
    bool operator>=(const Fraction&) const;

    // IO operators

    // iostream

    friend std::istream& operator>>(std::istream&, Fraction&);
    friend std::ostream& operator<<(std::ostream&, const Fraction&);

    // stdio

    void Input(const char*);
    void Output() const;
};

void Fraction::simplify() {
    if (denominator == 0) {
        std::cerr << "Error for denominator 0." << std::endl;
        exit(-1);
    }
    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }
    int p = std::gcd(numerator, denominator);
    numerator /= p;
    denominator /= p;
}

Fraction::Fraction(int n = 0, int d = 1) {
    numerator = n;
    denominator = d;
    simplify();
}
void Fraction::set(int n, int d) {
    numerator = n;
    denominator = d;
    simplify();
}
double Fraction::toDouble() const {
    return (double)numerator / denominator;
}

Fraction Fraction::operator+(const int& rhs) const {
    return Fraction(numerator + rhs * denominator, denominator);
}
Fraction Fraction::operator+(const Fraction& rhs) const {
    return Fraction(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}
Fraction operator+(const int& lhs, const Fraction& rhs) {
    return Fraction(lhs * rhs.denominator + rhs.numerator, rhs.denominator);
}
Fraction Fraction::operator-(const int& rhs) const {
    return Fraction(numerator - rhs * denominator, denominator);
}
Fraction Fraction::operator-(const Fraction& rhs) const {
    return Fraction(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
}
Fraction operator-(const int& lhs, const Fraction& rhs) {
    return Fraction(lhs * rhs.denominator - rhs.numerator, rhs.denominator);
}
Fraction Fraction::operator*(const int& rhs) const {
    return Fraction(numerator * rhs, denominator);
}
Fraction Fraction::operator*(const Fraction& rhs) const {
    return Fraction(numerator * rhs.numerator, denominator * rhs.denominator);
}
Fraction operator*(const int& lhs, const Fraction& rhs) {
    return Fraction(lhs * rhs.numerator, rhs.denominator);
}
Fraction Fraction::operator/(const int& rhs) const {
    return Fraction(numerator, denominator * rhs);
}
Fraction Fraction::operator/(const Fraction& rhs) const {
    return Fraction(numerator * rhs.denominator, denominator * rhs.numerator);
}
Fraction operator/(const int& lhs, const Fraction& rhs) {
    return Fraction(lhs * rhs.denominator, rhs.numerator);
}
Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}
Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}
Fraction& Fraction::operator+=(const int& rhs) {
    numerator += rhs * denominator;
    return *this;
}
Fraction& Fraction::operator+=(const Fraction& rhs) {
    numerator *= rhs.denominator;
    numerator += rhs.numerator * denominator;
    denominator *= rhs.denominator;
    return *this;
}
Fraction& Fraction::operator-=(const int& rhs) {
    numerator -= rhs * denominator;
    return *this;
}
Fraction& Fraction::operator-=(const Fraction& rhs) {
    numerator *= rhs.denominator;
    numerator -= rhs.numerator * denominator;
    denominator *= rhs.denominator;
    return *this;
}
Fraction& Fraction::operator*=(const int& rhs) {
    numerator *= rhs;
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    return *this;
}
Fraction& Fraction::operator/=(const int& rhs) {
    denominator *= rhs;
    return *this;
}
Fraction& Fraction::operator/=(const Fraction& rhs) {
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    return *this;
}
Fraction& Fraction::operator=(const int& rhs) {
    numerator = rhs;
    denominator = 1;
    return *this;
}
Fraction& Fraction::operator=(const Fraction& rhs) {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    return *this;
}

bool Fraction::operator==(const Fraction& rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}
bool Fraction::operator!=(const Fraction& rhs) const {
    return !(*this == rhs);
}
bool Fraction::operator<(const Fraction& rhs) const {
    return numerator * rhs.denominator < rhs.numerator* denominator;
}
bool Fraction::operator>(const Fraction& rhs) const {
    return rhs < *this;
}
bool Fraction::operator<=(const Fraction& rhs) const {
    return !(rhs < *this);
}
bool Fraction::operator>=(const Fraction& rhs) const {
    return !(*this < rhs);
}

std::istream& operator>>(std::istream& is, Fraction& rhs) {
    char c;
    is >> rhs.numerator >> c >> rhs.denominator;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Fraction& rhs) {
    if (rhs.denominator == 1) {
        os << rhs.numerator;
    } else {
        os << rhs.numerator << '/' << rhs.denominator;
    }
    return os;
}

void Fraction::Input(const char* format = "%d/%d") {
    scanf(format, &numerator, &denominator);
}
void Fraction::Output() const {
    if (denominator == 1)
        printf("%d", numerator);
    else
        printf("%d/%d", numerator, denominator);
}

//Tester
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    //Why need a tester?
    Fraction f1;
    std::cout << f1 << std::endl;
    Fraction f2(1, 2);
    std::cout << f2 << std::endl;
    f1 += 3*f2;
    std::cout << f1 << std::endl;
    f1 *= 3;
    std::cout << f1 << std::endl;
    // 不想测试了，直接丢了个测试包，没错误就交了。
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}