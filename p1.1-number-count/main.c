// Work on stdc17
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    int count;
    struct node* next;
} Node;

void Add(Node* head, int number) {
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->number == number) {
            current->next->count++;
            return;
        }
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }

    newNode->number = number;
    newNode->count = 1;
    newNode->next = NULL;
    current->next = newNode;
}

void Sort(Node* head) {
    Node* current = head->next;
    if (current == NULL) return;
    Node* tmp;
    while (current->next != NULL) {
        tmp = head;
        while (tmp->next->count >= current->next->count && tmp->next != current->next)
            tmp = tmp->next;
        if (tmp->next != current->next) {
            Node* tmp2 = current->next;
            current->next = tmp2->next;
            tmp2->next = tmp->next;
            tmp->next = tmp2;
        } else
            current = current->next;
    }
}

void Print(Node* node) {
    while (node != NULL) {
        printf("%d:%d\n", node->number, node->count);
        node = node->next;
    }
}

void DelTable(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int n;
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    head->number = -1;
    head->count = 0;
    head->next = NULL;
    while (scanf("%d", &n), n)
        Add(head, n);
    Sort(head);
    Print(head->next);
    DelTable(head);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
