# 第2章《求连通块》实验报告

21051117 卢俊成

## 主要数据结构和变量

- `a[][]` 原始数据
- `v[][]` 连通块标记
- `typedef struct Stack` 栈
- `typedef struct node` 节点

## 程序主要流程

1. 读入图面
2. 遍历，计算连通块数

## 程序主要函数功能

- `void visit(int x, int y, int m, int n, int* map, int* v)` 标记联通块
- 栈相关函数

## 已实现功能

全部题目要求功能

## 编译与运行信息

### 编译信息

```bash
/usr/bin/gcc -std=c17 -fdiagnostics-color=always -Wfatal-errors -Wall -Wextra -g 1.c -o 1 -lm
```

### 测试数据

#### 输入

```text
7 6
4 4 4 4 4 4
4 1 3 2 1 4
4 1 2 2 1 4
4 1 1 1 1 4
4 1 2 2 3 4
4 3 3 3 3 4
4 4 4 4 4 4
```

#### 输出

```text
6
```

## 源代码

### 递归版

```c
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
```

### 栈实现版

```c
// Work on stdc17
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define remark(x,y,n) ((x) * (n) + (y))

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct Stack {
    int length;
    Node* head;
} Stack;

Stack* Create() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(-1);
    }
    s->length = 0;
    s->head = NULL;
    return s;
}

void Destroy(Stack* s) {
    Node* current = s->head;
    Node* tmp;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(s);
}

int IsEmpty(Stack* s) {
    return s->length == 0;
}

int getTop(Stack* s) {
    if (IsEmpty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(-1);
    }
    return s->head->data;
}

void pop(Stack* s) {
    if (IsEmpty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(-1);
    }
    Node* tmp = s->head;
    s->head = s->head->next;
    free(tmp);
    s->length--;
}

void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = s->head;
    s->head = newNode;
    s->length++;
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
    Stack* s = Create();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) {
                block_count++;
                int flag = a[i][j];
                push(s, remark(i, j, n));
                while (!IsEmpty(s)) {
                    int x = getTop(s) / n;
                    int y = getTop(s) % n;
                    pop(s);
                    if (v[x][y] == 0) {
                        v[x][y] = 1;
                        if (x - 1 >= 0 && a[x - 1][y] == flag && v[x - 1][y] == 0)
                            push(s, remark(x - 1, y, n));
                        if (x + 1 < m && a[x + 1][y] == flag && v[x + 1][y] == 0)
                            push(s, remark(x + 1, y, n));
                        if (y - 1 >= 0 && a[x][y - 1] == flag && v[x][y - 1] == 0)
                            push(s, remark(x, y - 1, n));
                        if (y + 1 < n && a[x][y + 1] == flag && v[x][y + 1] == 0)
                            push(s, remark(x, y + 1, n));
                    }
                }
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
```
