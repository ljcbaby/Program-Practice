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
