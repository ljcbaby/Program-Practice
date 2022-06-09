#include <iostream>
#include <vector>
#include <algorithm>

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int n, r;
    std::cin >> n >> r;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    if (2 * r < n)
        std::sort(s.begin() + r, s.end() - r);
    for (int i = 0; i < n - 1; ++i) {
        std::cout << s[i] << " ";
    }
    std::cout << s[n - 1] << std::endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
