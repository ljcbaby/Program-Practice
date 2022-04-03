# 第2章《老鼠走迷宫》实验报告

21051117 卢俊成

## 主要数据结构和变量

- `typedef struct queue` 队列
- `int a[n][n]` 图面

## 程序主要流程

1. 读入大小、起点、终点、图面
2. 广搜
3. 输出路径

## 程序主要函数功能

- 队列相关函数
- `void print(int* map, int n, int x, int y)` 递归打印路径

## 已实现功能

全部题目要求功能

## 编译与运行信息

### 编译信息

```bash
/usr/bin/gcc -std=c17 -fdiagnostics-color=always -Wfatal-errors -Wall -Wextra -g 1.c -o 1 -lm
```

### 测试数据1

#### 输入

```text
10
1 0 4 9
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 0  0 -1  0 -1  0  0 -1  0 -1
-1  0 -1  0  0 -1  0  0  0 -1
-1  0 -1  0  0  0  0 -1 -1 -1
-1  0  0  0 -1  0 -1  0  0  0
-1 -1 -1  0 -1  0  0  0 -1 -1
-1 -1  0  0  0  0  0  0 -1 -1
-1  0  0  0  0 -1 -1 -1 -1 -1
-1  0  0  0  0  0  0  0  0 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
```

#### 输出

```text
16
(1, 1)
(2, 1)
(3, 1)
(4, 1)
(4, 2)
(4, 3)
(3, 3)
(3, 4)
(3, 5)
(4, 5)
(5, 5)
(5, 6)
(5, 7)
(4, 7)
(4, 8)
(4, 9)
```

## 源代码

```c
// Work on stdc17
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int x, y;
    struct node* next;
    struct node* prev;
} Node;

typedef struct queue {
    int length;
    Node* head;
    Node* tail;
} Queue;

Queue* Create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    q->length = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void Destroy(Queue* q) {
    Node* current = q->head;
    Node* tmp;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(q);
}

int IsEmpty(Queue* q) {
    return q->length == 0;
}

int Length(Queue* q) {
    return q->length;
}

int getTop_x(Queue* q) {
    if (IsEmpty(q)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }
    return q->head->x;
}

int getTop_y(Queue* q) {
    if (IsEmpty(q)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }
    return q->head->y;
}

void pop(Queue* q) {
    if (IsEmpty(q)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }
    Node* tmp = q->head;
    q->head = q->head->next;
    q->length--;
    free(tmp);
    if (q->length == 0) {
        q->tail = NULL;
    }
}

void push(Queue* q, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    if (IsEmpty(q)) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->length++;
}

void print(int* map, int n, int x, int y) {
    if (map[x * n + y] == 1) return;
    if (x - 1 >= 0 && map[(x - 1) * n + y] == map[x * n + y] - 1) print(map, n, x - 1, y);
    else if (x + 1 < n && map[(x + 1) * n + y] == map[x * n + y] - 1) print(map, n, x + 1, y);
    else if (y - 1 >= 0 && map[x * n + y - 1] == map[x * n + y] - 1) print(map, n, x, y - 1);
    else if (y + 1 < n && map[x * n + y + 1] == map[x * n + y] - 1) print(map, n, x, y + 1);
    printf("(%d, %d)\n", x, y);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int n;
    scanf("%d\n", &n);
    int x, y;
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= n || y < 0 || y >= n) {
        fprintf(stderr, "Error for input start point.\n");
        exit(1);
    }
    Queue* q = Create();
    push(q, x, y);
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= n || y < 0 || y >= n) {
        fprintf(stderr, "Error for input end point.\n");
        exit(1);
    }
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", a[i] + j);
    int dx, dy, step;
    dx = getTop_x(q);
    dy = getTop_y(q);
    step = (a[dx][dy] = 1) + 1;
    pop(q);
    while (dx != x || dy != y) {
        if (dx + 1 < n && a[dx + 1][dy] == 0) {
            push(q, dx + 1, dy);
            a[dx + 1][dy] = step;
        }
        if (dy + 1 < n && a[dx][dy + 1] == 0) {
            push(q, dx, dy + 1);
            a[dx][dy + 1] = step;
        }
        if (dx - 1 >= 0 && a[dx - 1][dy] == 0) {
            push(q, dx - 1, dy);
            a[dx - 1][dy] = step;
        }
        if (dy - 1 >= 0 && a[dx][dy - 1] == 0) {
            push(q, dx, dy - 1);
            a[dx][dy - 1] = step;
        }
        dx = getTop_x(q);
        dy = getTop_y(q);
        step = a[dx][dy] + 1;
        pop(q);
    }
    Destroy(q);
    printf("%d\n", a[x][y] - 1);
    print(*a, n, x, y);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
```
