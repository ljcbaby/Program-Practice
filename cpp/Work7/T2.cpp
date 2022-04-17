#include <cstdio>

class Group {
public:
    virtual int add(int x, int y) = 0;//输出加法的运算结果
    virtual int sub(int x, int y) = 0;//输出减法的运算结果
};

class GroupA : public Group {
public:
    int add(int x, int y) {
        return x + y;
    }
    int sub(int x, int y) {
        return x - y;
    }
};

class GroupB : public Group {
public:
    int add(int x, int y) {
        return x + y;
    }
    int sub(int x, int y) {
        int t = 0, exp = 1;
        while (x || y) {
            t += (x % 10 - y % 10 + 10) % 10 * exp;
            x /= 10;
            y /= 10;
            exp *= 10;
        }
        return t;
    }
};

class GroupC : public Group {
public:
    int add(int x, int y) {
        int t = 0, exp = 1;
        while (x || y) {
            t += (x % 10 + y % 10) % 10 * exp;
            x /= 10;
            y /= 10;
            exp *= 10;
        }
        return t;
    }
    int sub(int x, int y) {
        int t = 0, exp = 1;
        while (x || y) {
            t += (x % 10 - y % 10 + 10) % 10 * exp;
            x /= 10;
            y /= 10;
            exp *= 10;
        }
        return t;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    Group* group[3] = { new GroupA, new GroupB, new GroupC };
    int n;
    scanf("%d", &n);
    int stu[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stu[i]);
    }
    int temp;
    int x, y;
    char op;
    while (scanf("%d", &temp), temp) {
        scanf("%d%c%d", &x, &op, &y);
        switch (op) {
        case '+':
            printf("%d\n", group[stu[temp - 1] - 1]->add(x, y));
            break;
        case '-':
            printf("%d\n", group[stu[temp - 1] - 1]->sub(x, y));
            break;
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
