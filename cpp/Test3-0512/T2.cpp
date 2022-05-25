#include <iostream>
using namespace std;

template<class T>
class Vector {
public:
    int n;
    T* a;
    Vector(int n = 0) : n(n), a(new T[n]) {}
    Vector(const Vector& v) : n(v.n), a(new T[n]) {
        for (int i = 0; i < n; i++)
            a[i] = v.a[i];
    }
    friend istream& operator>>(istream& is, Vector& v) {
        for (int i = 0; i < v.n; i++)
            is >> v.a[i];
        return is;
    }
    friend ostream& operator<<(ostream& os, const Vector& v) {
        for (int i = 0; i < v.n; i++)
            os << v.a[i] << " ";
        return os;
    }
};
template<class T>
void Sort(Vector<T>& a) {
    for (int i = 0; i < a.n; i++)
        for (int j = i + 1; j < a.n; j++)
            if (a.a[i] > a.a[j])
                swap(a.a[i], a.a[j]);
}

int main() {
    int n;
    cin >> n;
    Vector<int> a(n);
    cin >> a;
    Sort(a);
    cout << a << endl;

    int m;
    cin >> m;
    Vector<double> b(m);
    cin >> b;
    Sort(b);
    cout << b << endl;
}