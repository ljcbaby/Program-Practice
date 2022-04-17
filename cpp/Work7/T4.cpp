#include <cstdio>
#include <iostream>
#include <iomanip>

class Dot {
private:
    float x, y;
public:
    Dot(float x, float y) : x(x), y(y) {
        std::cout << "Dot constructor called" << std::endl;
    }
    ~Dot() {
        std::cout << "Dot destructor called" << std::endl;
    }
};

class Cir : public Dot {
private:
    float r;
public:
    Cir(float x, float y, float r) : Dot(x, y), r(r) {
        std::cout << "Cir constructor called" << std::endl;
    }
    ~Cir() {
        std::cout << "Cir destructor called" << std::endl;
    }
    float getArea() {
        return 3.14f * r * r;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    float x, y, r;
    std::cin >> x >> y >> r;
    Cir c(x, y, r);
    std::cout << std::fixed << std::setprecision(2) << c.getArea() << std::endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
