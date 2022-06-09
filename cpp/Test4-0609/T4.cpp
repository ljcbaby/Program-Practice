#include <cstdio>
#include <cstring>
#include <iostream>

class mystring {
public:
    mystring() {
        printf("construct 0\n");
        buf = new char[1];
        buf[0] = '\0';
    }
    mystring(const char *s) {
        printf("construct 1\n");
        buf = new char[strlen(s) + 1];
        strcpy(buf, s);
    }
    ~mystring() {
        printf("destruct\n");
        delete[] buf;
    }
    mystring& operator=(const mystring &s) {
        if (this == &s) return *this;
        delete[] buf;
        buf = new char[strlen(s.buf) + 4];
        strcpy(buf, "c++");
        strcat(buf, s.buf);
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const mystring &s) {
        os << s.buf;
        return os;
    }
    friend std::istream &operator>>(std::istream &is, mystring &s) {
        char buf[100];
        is >> buf;
        delete[] s.buf;
        s.buf = new char[strlen(buf) + 1];
        strcpy(s.buf, buf);
        return is;
    }
    char *buf;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    char ss[100];
    std::cin >> ss;
    mystring s(ss);
    std::cout << s << std::endl;
    mystring s2;
    s2 = s;
    std::cout << s2 << std::endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
