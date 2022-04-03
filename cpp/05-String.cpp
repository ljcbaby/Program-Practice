#include <cstdio>
#include <iostream>
#include <cstring>

class String {
private:
    char* Buffer;
    int Length;
    explicit String(int length) {
        Buffer = new char[length + 1];
        Length = length;
    }
public:
    String();
    String(const char*);
    ~String();
    String(const String&);
    String(String&&) noexcept;
    String& operator=(const String&);
    String& operator=(String&&) noexcept;
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend String operator+(const String&, const String&);
    String substr(int, int);
    char& operator[](int);
    char operator[](int) const;
    operator const char* () const;
};

String::String() {
    Buffer = new char[1];
    Buffer[0] = '\0';
    Length = 0;
}

String::String(const char* str) {
    Length = strlen(str);
    Buffer = new char[Length + 1];
    strcpy(Buffer, str);
}

String::~String() {
    delete[ ] Buffer;
}

String::String(const String& rhs) : Buffer(NULL) {
    Length = rhs.Length;
    Buffer = new char[Length + 1];
    strcpy(Buffer, rhs.Buffer);
}

String::String(String&& rhs) noexcept {
    Buffer = rhs.Buffer;
    Length = rhs.Length;
    rhs.Buffer = NULL;
    rhs.Length = 0;
}

String& String::operator=(const String& rhs) {
    if (this != &rhs) {
        delete[ ] Buffer;
        Length = rhs.Length;
        Buffer = new char[Length + 1];
        strcpy(Buffer, rhs.Buffer);
    }
    return *this;
}

String& String::operator=(String&& rhs) noexcept {
    if (this != &rhs) {
        delete[ ] Buffer;
        Buffer = rhs.Buffer;
        Length = rhs.Length;
        rhs.Buffer = NULL;
        rhs.Length = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.Buffer;
    return os;
}

String operator+(const String& lhs, const String& rhs) {
    String result(lhs.Length + rhs.Length);
    strcpy(result.Buffer, lhs.Buffer);
    strcat(result.Buffer, rhs.Buffer);
    return result;
}

String String::substr(int start, int length) {
    String result(length);
    strncpy(result.Buffer, Buffer + start, length);
    return result;
}

char& String::operator[](int index) {
    return Buffer[index];
}

char String::operator[](int index) const {
    return Buffer[index];
}

String::operator const char* () const {
    return Buffer;
}

//Tester from Ex4.4
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    char bufs1[256], bufs2[256];
    std::cin >> bufs1 >> bufs2;
    String s[4]{ String(bufs1), String(bufs2) };
    char op;
    int i, j, k, l, pos;
    while (std::cin >> op) {
        switch (op) {
        case 'P':
            std::cin >> i;
            std::cout << s[i - 1] << std::endl;
            break;
        case 'A':
            std::cin >> i >> j;
            s[j - 1] = s[i - 1];
            break;
        case 'C':
            std::cin >> i >> j >> k;
            s[k - 1] = s[i - 1] + s[j - 1];
            break;
        case 'F':
            std::cin >> i >> pos >> l >> k;
            s[k - 1] = s[i - 1].substr(pos, l);
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