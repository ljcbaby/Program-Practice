#include <iostream>
#include <vector>

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int n;
    while (~scanf("%d", &n)) {
        std::string tmp;
        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            s.push_back(tmp);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (s[j + 1] + s[j] > s[j] + s[j + 1]) {
                    std::swap(s[j], s[j + 1]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            std::cout << s[i];
        }
        std::cout << std::endl;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
