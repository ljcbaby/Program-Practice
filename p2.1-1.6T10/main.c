// Work on stdc17
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    int length;
    Node* head;
    Node* tail;
} Queue;

Queue* Q_Create() {
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

void Q_Destroy(Queue* q) {
    Node* current = q->head;
    Node* tmp;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(q);
}

int Q_IsEmpty(Queue* q) {
    return q->length == 0;
}

int Q_Length(Queue* q) {
    return q->length;
}

int Q_getTop(Queue* q) {
    if (Q_IsEmpty(q)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }
    return q->head->data;
}

void Q_pop(Queue* q) {
    if (Q_IsEmpty(q)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }
    Node* tmp = q->head;
    q->head = q->head->next;
    free(tmp);
    q->length--;
    if (q->length == 0) {
        q->tail = NULL;
    }
}

void Q_push(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (Q_IsEmpty(q)) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->length++;
}

typedef struct Stack {
    int length;
    Node* head;
} Stack;

Stack* S_Create() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    s->length = 0;
    s->head = NULL;
    return s;
}

void S_Destroy(Stack* s) {
    Node* current = s->head;
    Node* tmp;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(s);
}

int S_IsEmpty(Stack* s) {
    return s->length == 0;
}

int S_getTop(Stack* s) {
    if (S_IsEmpty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }
    return s->head->data;
}

void S_pop(Stack* s) {
    if (S_IsEmpty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }
    Node* tmp = s->head;
    s->head = s->head->next;
    free(tmp);
    s->length--;
}

void S_push(Stack* s, int data) {
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    Queue* q = Q_Create();
    Stack* s = S_Create();
    int t;
    while (~scanf("%d", &t))
        if (t > 0)
            S_push(s, t);
        else
            Q_push(q, t);
    while (!S_IsEmpty(s)) {
        printf("%d ", S_getTop(s));
        S_pop(s);
    }
    printf("\n");
    while (!Q_IsEmpty(q)) {
        printf("%d ", Q_getTop(q));
        Q_pop(q);
    }
    Q_Destroy(q);
    S_Destroy(s);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}