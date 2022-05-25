#include <iostream>
#include <map>

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    std::map<int, int> m;
    int t;
    while (std::cin >> t) {
        m[t]++;
    }
    int t2 = 0;
    for (auto it = m.begin();it != m.end();it++) {
        if (it->second > t2) {
            t2 = it->second;
            t = it->first;
        }
    }
    std::cout << t << std::endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
