#include <iostream>
#include <vector>
#include <algorithm>

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int t;
    std::vector<int> v;
    std::cout << "从标准设备读入数据，直到输入是非整型数据为止\n";
    while (scanf("%d", &t) == 1) {
        v.push_back(t);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
