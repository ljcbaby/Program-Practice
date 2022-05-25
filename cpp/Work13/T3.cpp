#include<iostream>
#include<unordered_set>

using namespace std;

// 将 n 进制数转换成 10 进制数
int nToTen(string s, int n) {
    int x = 0;
    // 秦九韶算法
    for (char c : s) x = n * x + (c - 48);
    return x;
}

int main() {

    string b;   // 二进制数
    string t;   // 三进制数
    std::unordered_set<int> h;  // 存储更改二进制数其中一位后生成的十进制数

    cin >> b >> t;

    // '&'对原数组进行操作
    for (char& c : b) {
        c ^= 1; // 更改一位
        int x = nToTen(b, 2);   // 将二进制数转换成十进制数
        h.insert(x);    // 记录该十进制数
        c ^= 1; // 复原
    }

    for (char& c : t) {
        char temp = c;
        for (int i = 0; i < 3; i++) {
            if (temp - 48 != i) {
                c = i + 48; // 更改一位
                int x = nToTen(t, 3);   // 将三进制数转换成十进制数
                if (h.count(x))  // 判断该十进制数能否由之前的二进制数更改一位得到
                {
                    cout << x << endl;
                    return 0;
                }
            }
        }
        c = temp;   // 复原
    }
}
