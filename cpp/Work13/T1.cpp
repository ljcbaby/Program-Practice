#include <iostream>

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    std::cout << "year:";
    putchar(getchar());
    putchar(getchar());
    putchar(getchar());
    putchar(getchar());
    putchar('\n');
    std::cout << "department:";
    putchar(getchar());
    putchar(getchar());
    putchar('\n');
    std::cout << "class:";
    putchar(getchar());
    putchar(getchar());
    putchar('\n');
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
