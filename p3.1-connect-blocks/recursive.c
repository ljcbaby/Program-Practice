// Work on stdc17
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void visit(int x, int y, int m, int n, int* map, int* v) {
    if (x - 1 >= 0 && map[(x - 1) * n + y] == map[x * n + y] && v[(x - 1) * n + y] == 0) {
        v[(x - 1) * n + y] = 1;
        visit(x - 1, y, m, n, map, v);
    }
    if (x + 1 < m && map[(x + 1) * n + y] == map[x * n + y] && v[(x + 1) * n + y] == 0) {
        v[(x + 1) * n + y] = 1;
        visit(x + 1, y, m, n, map, v);
    }
    if (y - 1 >= 0 && map[x * n + y - 1] == map[x * n + y] && v[x * n + y - 1] == 0) {
        v[x * n + y - 1] = 1;
        visit(x, y - 1, m, n, map, v);
    }
    if (y + 1 < n && map[x * n + y + 1] == map[x * n + y] && v[x * n + y + 1] == 0) {
        v[x * n + y + 1] = 1;
        visit(x, y + 1, m, n, map, v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n], v[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    memset(v, 0, sizeof(v));
    int block_count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) {
                block_count++;
                visit(i, j, m, n, a[0], v[0]);
            }
        }
    }
    printf("%d\n", block_count);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
