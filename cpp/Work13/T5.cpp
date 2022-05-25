#include <iostream>
#include <map>

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2;i * i <= n;i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    std::map<char, int> m;
    std::string s;
    std::cin >> s;
    for (int i = 0;i < s.size();i++) {
        m[s[i]]++;
    }
    int ma = 0, mi = 0x7fffffff;
    for (auto it = m.begin();it != m.end();it++) {
        if (it->second > ma)
            ma = it->second;
        if (it->second < mi)
            mi = it->second;
    }
    if (is_prime(ma - mi)) {
        std::cout << "Lucky Word" << std::endl << ma - mi;
    } else {
        std::cout << "No Answer" << std::endl << 0;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
