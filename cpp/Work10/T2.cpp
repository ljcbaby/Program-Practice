#include <iostream>

template <class T>
class MyArray {
private:
    T* data;
    int size;
public:
    MyArray() {
        data = NULL;
        size = 0;
    }
    MyArray(int size) {
        this->size = size;
        data = new T[size];
    }
    ~MyArray();
    bool check();
    T& operator[](int index) {
        return data[index];
    }
    void sort() {
        for (int i = 0; i < size; i++) {
            std::cin >> data[i];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (data[j] > data[j + 1]) {
                    T tmp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = tmp;
                }
            }
        }
    }
    void display() {
        std::cout << data[0];
        for (int i = 1; i < size; i++) {
            std::cout << " " << data[i];
        }
        std::cout << std::endl;
    }
};

template<class T>
MyArray<T>::~MyArray() { delete[ ] data; }

template<class T>
bool MyArray<T>::check() {
    int i;
    for (i = 0;i < size - 1;i++)
        if (data[i] > data[i + 1]) { std::cout << "ERROR!" << std::endl;return false; }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    MyArray<int>* pI;
    MyArray<float>* pF;
    MyArray<char>* pC;
    int ty, size;
    std::cin >> ty;
    while (ty > 0) {
        std::cin >> size;
        switch (ty) {
        case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
        case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
        case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
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
