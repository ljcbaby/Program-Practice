#include <iostream>
#include <algorithm>

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << std::endl;
    } while (std::next_permutation(s.begin(), s.end()));
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
