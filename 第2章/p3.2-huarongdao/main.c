// Work on stdc17
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    unsigned long long map;
    struct node* next;
} Node;

Node* HashTable[1 << 27] = { NULL };

unsigned long long map2int(const unsigned char* a, const unsigned char* n) {
    register unsigned long long res = 0;
    register unsigned char p = *n * *n;
    for (register unsigned char i = 0;i < p;i++) {
        res = res * p + a[i];
    }
    return res;
}

void int2map(register unsigned long long a, unsigned char* b, const unsigned char* n) {
    register unsigned char p = *n * *n;
    for (register unsigned char i = p - 1;i < p;i--) {
        b[i] = a % p;
        a /= p;
    }
}

Node* CreateNode(const unsigned long long a) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->map = a;
    register unsigned int hash = a;
    hash &= 0x07FFFFFF;
    newnode->next = HashTable[hash];
    HashTable[hash] = newnode;
    return newnode;
}

int check(const unsigned long long* a) {
    register unsigned int hash = *a;
    hash &= 0x07FFFFFF;
    register Node* p = HashTable[hash];
    while (p != NULL) {
        if (p->map == *a) {
            return 0;
        }
        p = p->next;
    }
    return 1;
}

void delete_map() {
    for (register unsigned int i = 0;i < (1 << 24);i++) {
        register Node* p = HashTable[i];
        while (p != NULL) {
            register Node* q = p;
            p = p->next;
            free(q);
        }
    }
}

typedef struct qnode {
    unsigned char* step;
    int step_num;
    Node* map;
    struct qnode* next;
} QNode;

typedef struct queue {
    unsigned int length;
    QNode* head;
    QNode* tail;
} Queue;

Queue* Create() {
    Queue* s = (Queue*)malloc(sizeof(Queue));
    if (s == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(-1);
    }
    s->length = 0;
    s->head = NULL;
    s->tail = NULL;
    return s;
}

QNode* CreateQNode() {
    QNode* s = (QNode*)malloc(sizeof(QNode));
    if (s == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(-1);
    }
    s->step = (unsigned char*)malloc(sizeof(unsigned char) * 64);
    s->next = NULL;
    return s;
}

void Destroy(Queue* s) {
    QNode* current = s->head;
    QNode* tmp;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->step);
        free(tmp);
    }
    free(s);
}

int IsEmpty(Queue* s) {
    return s->length == 0;
}

QNode* getTop(Queue* s) {
    if (IsEmpty(s)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(-1);
    }
    return s->head;
}

void push(Queue* s, QNode* n) {
    if (s->length == 0) {
        s->head = n;
        s->tail = n;
    } else {
        s->tail->next = n;
        s->tail = n;
    }
    s->length++;
}

void pop(Queue* s) {
    if (IsEmpty(s)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(-1);
    }
    QNode* tmp = s->head;
    s->head = s->head->next;
    free(tmp);
    s->length--;
    if (s->length == 0) {
        s->tail = NULL;
    }
}

void print_step(QNode* n) {
    unsigned char step;
    for (register unsigned char i = 0;i <= n->step_num;i++) {
        step = (n->step[i / 4] >> (6 - 2 * (i % 4))) & 0x03;
        switch (step) {
        case 0:
            printf("↑\n");
            break;
        case 1:
            printf("↓\n");
            break;
        case 2:
            printf("←\n");
            break;
        case 3:
            printf("→\n");
            break;
        }
    }
}

void swap(unsigned char* a, unsigned char* b) {
    register unsigned char tmp = *a;
    *a = *b;
    *b = tmp;
}

int is_valid(unsigned char* a, unsigned char* n) {
    register unsigned char exp = 0;
    for (register unsigned char i = 1;i < *n * *n;i++) {
        for (register unsigned char j = 0;j < i;j++) {
            if (a[j] > a[i]) {
                exp++;
            }
        }
        if (a[i] == 0) {
            exp += i / *n;
            exp += i % *n;
        }
    }
    return exp % 2 == (*n - 1) % 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    unsigned char n;
    scanf("%hhd", &n);
    if (n >= 5) {
        printf("太复杂\n");
        return 0;
    }
    unsigned char* a = (unsigned char*)malloc(sizeof(unsigned char) * n * n);
    for (unsigned char i = 0;i < n * n;i++)
        a[i] = i + 1;
    a[n * n - 1] = 0;
    const unsigned long long start = map2int(a, &n);
    for (unsigned char i = 0;i < n * n;i++)
        scanf("%hhd", a + i);
    if (!is_valid(a, &n)) {
        printf("无解\n");
        return 0;
    }
    Node* map_node = CreateNode(map2int(a, &n));
    Queue* q = Create();
    QNode* cur = CreateQNode();
    memset(cur->step, 0, sizeof(unsigned char) * 64);
    cur->step_num = -1;
    cur->map = map_node;
    push(q, cur);
    while (!IsEmpty(q)) {
        cur = getTop(q);
        if (cur->map->map == start)
            break;
        if (n >= 5 && q->length >= 1 << 20)
            break;
        int2map(cur->map->map, a, &n);
        int s0 = 0;
        for (int i = 0;i < n * n;i++) {
            if (a[i] == 0) {
                s0 = i;
                break;
            }
        }
        if (s0 - n >= 0) {
            swap(a + s0, a + s0 - n);
            unsigned long long new_map = map2int(a, &n);
            if (check(&new_map)) {
                map_node = CreateNode(new_map);
                QNode* new_node = CreateQNode();
                memcpy(new_node->step, cur->step, sizeof(unsigned char) * 64);
                new_node->step_num = cur->step_num + 1;
                new_node->map = map_node;
                push(q, new_node);
            }
            swap(a + s0, a + s0 - n);
        }
        if (s0 + n < n * n) {
            swap(a + s0, a + s0 + n);
            unsigned long long new_map = map2int(a, &n);
            if (check(&new_map)) {
                map_node = CreateNode(new_map);
                QNode* new_node = CreateQNode();
                memcpy(new_node->step, cur->step, sizeof(unsigned char) * 64);
                new_node->step_num = cur->step_num + 1;
                new_node->step[new_node->step_num / 4] |= 0x40 >> ((new_node->step_num % 4) * 2);
                new_node->map = map_node;
                push(q, new_node);
            }
            swap(a + s0, a + s0 + n);
        }
        if (s0 - 1 >= 0 && s0 % n != 0) {
            swap(a + s0, a + s0 - 1);
            unsigned long long new_map = map2int(a, &n);
            if (check(&new_map)) {
                map_node = CreateNode(new_map);
                QNode* new_node = CreateQNode();
                memcpy(new_node->step, cur->step, sizeof(unsigned char) * 64);
                new_node->step_num = cur->step_num + 1;
                new_node->step[new_node->step_num / 4] |= 0x80 >> ((new_node->step_num % 4) * 2);
                new_node->map = map_node;
                push(q, new_node);
            }
            swap(a + s0, a + s0 - 1);
        }
        if (s0 + 1 < n * n && s0 % n != n - 1) {
            swap(a + s0, a + s0 + 1);
            unsigned long long new_map = map2int(a, &n);
            if (check(&new_map)) {
                map_node = CreateNode(new_map);
                QNode* new_node = CreateQNode();
                memcpy(new_node->step, cur->step, sizeof(unsigned char) * 64);
                new_node->step_num = cur->step_num + 1;
                new_node->step[new_node->step_num / 4] |= 0xc0 >> ((new_node->step_num % 4) * 2);
                new_node->map = map_node;
                push(q, new_node);
            }
            swap(a + s0, a + s0 + 1);
        }
        pop(q);
    }
    printf("%d\n", cur->step_num + 1);
    print_step(cur);
    Destroy(q);
    delete_map();
    free(a);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
