#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int x, y;
    double z = 0;
    cin >> x >> y;
    try {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}

double division(int a, int b){
    if (b == 0) {
        throw "Divided by zero!";
    }
    return (double)a / b;
}
