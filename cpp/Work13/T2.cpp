#include <iostream>


int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int n, k = 0;
    while (scanf("%d", &n), n) {
        std::string a[n];
        for (int i = 0;i < n / 2;i++) {
            std::cin >> a[i];
            std::cin >> a[n - i - 1];
        }
        if (n % 2)
            std::cin >> a[n / 2];
        std::cout << "SET " << ++k << std::endl;
        for (int i = 0;i < n;i++) {
            std::cout << a[i] << std::endl;
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
