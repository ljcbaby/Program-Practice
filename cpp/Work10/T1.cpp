#include <iostream>
#include <cstring>

template <class T>
class Vector {
private:
    T* data;
    int size;
public:
    Vector() {
        data = NULL;
        size = 0;
    }
    Vector(int size) {
        this->size = size;
        data = new T[size];
    }
    Vector(const Vector& other) {
        this->size = other.size;
        data = new T[other.size];
        memcpy(data, other.data, sizeof(T) * other.size);
    }
    ~Vector() {
        delete[ ] data;
    }
    const Vector& operator=(const Vector<T>& v) {
        this->size = v.size;
        this->data = new T[v.size];
        memcpy(this->data, v.data, v.size * sizeof(T));
        return *this;
    }
    Vector<T>& operator=(Vector<T>&& v) {
        this->size = v.size;
        this->data = v.data;
        v.data = NULL;
        return *this;
    }
    int add(T value) {
        T* newData = new T[size + 1];
        memcpy(newData, data, sizeof(T) * size);
        newData[size] = value;
        delete[ ] data;
        data = newData;
        size++;
        return size - 1;
    }
    void remove(int index) {
        Vector<T> tmp(size - 1);
        memcpy(tmp.data, data, index * sizeof(T));
        memcpy(tmp.data + index, data + index + 1, (size - index - 1) * sizeof(T));
        *this = tmp;
    }
    T& operator[](int index) {
        return data[index];
    }
    int get_size() {
        return size;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    Vector<int> vint;
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        //    add() can inflate the vector automatically
        vint.add(i);
    }
    //    get_size() returns the number of elements stored in the vector
    std::cout << vint.get_size() << std::endl;
    std::cout << vint[m] << std::endl;
    //    remove() removes the element at the index which begins from zero
    vint.remove(m);
    std::cout << vint.add(-1) << std::endl;
    std::cout << vint[m] << std::endl;
    Vector<int> vv = vint;
    std::cout << vv[vv.get_size() - 1] << std::endl;
    vv.add(m);
    std::cout << vint.get_size() << std::endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
