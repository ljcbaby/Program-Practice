#include <cstdio>

class Staff {
private:
    int num;
    char* name;
    int BasicSale;
public:
    Staff(int num, char* name, int BasicSale) {
        this->num = num;
        this->name = name;
        this->BasicSale = BasicSale;
    }
    void show() {
        printf("num:%d\n", num);
        printf("name:%s\n", name);
        printf("BasicSale:%d\n", BasicSale);
    }
};

class saleman : virtual public Staff {
private:
    int personAmount;
public:
    saleman(int num, char* name, int BasicSale, int personAmount) : Staff(num, name, BasicSale) {
        this->personAmount = personAmount;
    }
    void show() {
        printf("personAmount:%d\n", personAmount);
    }
};

class manager : virtual public Staff {
private:
    int tatalAmount;
public:
    manager(int num, char* name, int BasicSale, int tatalAmount) : Staff(num, name, BasicSale) {
        this->tatalAmount = tatalAmount;
    }
    void show() {
        printf("tatalAmount:%d\n", tatalAmount);
    }
};

class SaleManager : public saleman, public manager {
public:
    SaleManager(int num, char* name, int BasicSale, int personAmount, int tatalAmount) : Staff(num, name, BasicSale), saleman(num, name, BasicSale, personAmount), manager(num, name, BasicSale, tatalAmount) {}
    void show() {
        Staff::show();
        saleman::show();
        manager::show();
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    SaleManager sm(11, "zhangsan", 100, 200, 500); // 参数含义依次为编号，姓名，基本工资，个人有销售额，销售总额
    sm.show();
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
