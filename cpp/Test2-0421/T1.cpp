#include <iostream>
#include <string>

class Base {
protected:
    int ID;
    std::string name;
    int wage;
public:
    Base(int id, std::string n, int w) {
        ID = id;
        name = n;
        wage = w;
    }
    virtual void print() {
        printf("ID: %d\n", ID);
        printf("name: %s\n", name.c_str());
        printf("wage: %d\n", wage);
    }
};

class manager : public Base {
public:
    manager(int id, std::string n) : Base(id, n, 80000) {}
    void print() {
        Base::print();
    }
};

class Technician : public Base {
private:
    int hour;
public:
    Technician(int id, std::string n, int h) : Base(id, n, h * 100) {
        hour = h;
    }
    void print() {
        Base::print();
        printf("hour: %d\n", hour);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int type;
    while (~scanf("%d", &type), type) {
        if (type == 2) {
            int id, hour;
            std::string name;
            std::cin >> id >> name >> hour;
            Technician t(id, name, hour);
            t.print();
        } else {
            int id;
            std::string name;
            std::cin >> id >> name;
            manager m(id, name);
            m.print();
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
