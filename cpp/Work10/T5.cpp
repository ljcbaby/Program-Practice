#include <iostream>

template<class T>
class Num {
private:
    T a, b;
public:
    Num(T a, T b) :a(a), b(b) {}
    T max() { return a > b ? a : b; }
    T min() { return a < b ? a : b; }
    T sum() { return a + b; }
    T minus() { return a - b; }
    T multiply() { return a * b; }
    T divide() { return a / b; }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int n1, n2;
    std::cin >> n1 >> n2;
    Num<int> num(n1, n2);
    std::cout << num.max() << " " << num.min() << " " << num.sum() << " " << num.minus() << " " << num.multiply() << " " << num.divide() << std::endl;
    double n3, n4;
    std::cin >> n3 >> n4;
    Num<double> num2(n3, n4);
    std::cout << num2.max() << " " << num2.min() << " " << num2.sum() << " " << num2.minus() << " " << num2.multiply() << " " << num2.divide() << std::endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
