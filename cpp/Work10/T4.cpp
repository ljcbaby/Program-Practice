#include <iostream>
#include <string>
using namespace std;

template<class T>
T myMax(T a, T b) {
    return a > b ? a : b;
}

template<class T>
T myMax(T a, T b, T c) {
    return myMax(myMax(a, b), c);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int a, b, c;
    double s, t;
    string x, y;
    cin >> x >> y;        cout << myMax(x, y) << endl;
    cin >> a >> b >> c;     cout << myMax(a, b, c) << endl;
    cin >> s >> t;       cout << myMax(s, t) << endl;
    cin >> a >> b;     cout << myMax(a, b) << endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
