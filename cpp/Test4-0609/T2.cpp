#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 形状类
public:
    double getArea()  // 求面积
    {
        return -1;
    }
    double getPerimeter() // 求周长
    {
        return -1;
    }
};

class RegularPolygon : public shape { // 正多边形类
private:
    int n; // 边数
    double side; // 边长
public:
    RegularPolygon(int n, double side) : n(n), side(side) {}
    double getArea() // 求面积
    {
        return n * side * side / (4 * tan(M_PI / n));
    }
    double getPerimeter() // 求周长
    {
        return n * side;
    }
};

int main() {
    int n;
    double s;

    cin >> n >> s;
    RegularPolygon p(n, s);
    cout << p.getArea() << endl;

    cout << p.getPerimeter() << endl;

    return 0;
}
