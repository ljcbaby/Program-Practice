// Work on stdc17
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        exit(1);
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
        exit(1);
    }
    return s->head->data;
}

void pop(Stack* s) {
    if (IsEmpty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
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
        exit(1);
    }
    newNode->data = data;
    newNode->next = s->head;
    s->head = newNode;
    s->length++;
}

int level(char c) {
    if (c == ')') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int operate(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    Stack* num = Create();
    Stack* op = Create();
    char ch;
    int n, num1, num2;
    push(op, '(');
    while ((ch = getchar()) != '#') {
        if (isdigit(ch)) {
            n = ch - '0';
            while (isdigit(ch = getchar()))
                n = n * 10 + ch - '0';
            push(num, n);
        }
        if (ch == '(') {
            push(op, ch);
            continue;
        }
        if (ch == ')') {
            while (getTop(op) != '(') {
                num1 = getTop(num);
                pop(num);
                num2 = getTop(num);
                pop(num);
                push(num, operate(num2, num1, getTop(op)));
                pop(op);
            }
            pop(op);
            continue;
        }
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (IsEmpty(op) || (level(ch) > level(getTop(op)))) {
                push(op, ch);
                continue;
            }
            num1 = getTop(num);
            pop(num);
            num2 = getTop(num);
            pop(num);
            push(num, operate(num2, num1, getTop(op)));
            pop(op);
            push(op, ch);
        }
    }
    while (getTop(op) != '(') {
        num1 = getTop(num);
        pop(num);
        num2 = getTop(num);
        pop(num);
        push(num, operate(num2, num1, getTop(op)));
        pop(op);
    }
    pop(op);
    printf("%d\n", getTop(num));
    Destroy(num);
    Destroy(op);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}