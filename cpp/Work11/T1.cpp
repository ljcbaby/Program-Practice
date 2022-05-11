#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    double a, b, c;
    cin >> a >> b >> c;
    try {
        Time(a, b, c);
    }
    catch (char* arg) {
        cout << arg << endl;
    }
    catch (...) {
        cout << "I have catched an exception!" << endl;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}

void Time(int a, int b, int c) {
    if (a > 24 || a < 0) {
        throw "The time is wrong!";
    } else if (b > 59 || b < 0) {
        throw "The time is wrong!";
    } else if (c > 59 || c < 0) {
        throw "The time is wrong!";
    } else {
        cout << "The current time is: " << a << ":" << b << ":" << c << endl;
    }
}
