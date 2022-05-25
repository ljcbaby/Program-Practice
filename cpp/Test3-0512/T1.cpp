#include <iostream>
#include <exception>
#include <limits>
using namespace std;

class MyComplex {
public:
    double real;
    double imag;
    MyComplex(double real = 0, double imag = 0) : real(real), imag(imag) {}
    MyComplex operator+(const MyComplex& z) const {
        return MyComplex(real + z.real, imag + z.imag);
    }
    MyComplex operator-(const MyComplex& z) const {
        return MyComplex(real - z.real, imag - z.imag);
    }
    MyComplex operator*(const MyComplex& z) const {
        return MyComplex(real * z.real - imag * z.imag, real * z.imag + imag * z.real);
    }
    MyComplex operator/(const double& z) const {
        return MyComplex(real / z, imag / z);
    }
    MyComplex operator/(const MyComplex& z) const {
        MyComplex az(z.real, -z.imag);
        if (z.real == 0 && z.imag == 0) throw runtime_error("Divisor is 0");
        return *this * az / (z.real * z.real + z.imag * z.imag);
    }
    friend ostream& operator<<(ostream& os, const MyComplex& z) {
        char sign = z.imag < 0 ? '-' : '+';
        os << "(" << z.real << sign << abs(z.imag) << "i)";
        return os;
    }
    friend istream& operator>>(istream& is, MyComplex& z) {
        is >> z.real >> z.imag;
        return is;
    }
};

int main() { // 不可修改main函数中的代码，否则OJ将给你的程序打0分
    MyComplex z1, z2;
    cin >> z1;
    cin >> z2;
    try {
        cout << "z1 + z2 = " << z1 + z2 << endl;
        cout << "z1 - z2 + z1 = " << z1 - z2 + z1 << endl;
        cout << "z1 * z2 - z1 = " << z1 * z2 - z1 << endl;
        cout << "z1 / z2 + z1 = " << z1 / z2 + z1 << endl;
        cout << "z2 - z1 / z1 = " << z2 - z1 / z1 << endl;
        cout << "Finished";
    }
    catch (exception& e) {         // catch父类异常类型，也可以捕获子类异常
        cout << e.what() << endl;  // waht()函数将存放在异常对象中的信息取出来
        cout << "Unexpected Error";
    }
    // GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
#endif
    return 0;
}
