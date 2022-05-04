#include <iostream>
#include <string>

template <class T>
void sort(T* a, int size) {
    for (int i = 0; i < size; i++)
        std::cin >> a[i];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (a[j] > a[j + 1]) {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

template <class T>
void display(T* a, int size) {
    for (int i = 0; i < size - 1; i++) cout << a[i] << ' ';
    cout << a[size - 1] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    const int SIZE = 10;
    int a[SIZE];
    char b[SIZE];
    double c[SIZE];
    std::string d[SIZE];
    int ty, size;
    std::cin >> ty;
    while (ty > 0) {
        std::cin >> size;
        switch (ty) {
        case 1:sort(a, size); display(a, size); break;
        case 2:sort(b, size); display(b, size); break;
        case 3:sort(c, size); display(c, size); break;
        case 4:sort(d, size); display(d, size); break;
        }
        std::cin >> ty;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
