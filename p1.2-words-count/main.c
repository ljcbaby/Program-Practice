// Work on stdc17
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXLEN 1000

typedef struct word {
    char* w;
    int count;
    struct word* next;
} Word;

char* stopword[ ] = { "you","he","she","they","it",
                     "the","an","by","for","mr",
                     "in","on","at","but","be","new",
                     "of","and","or","to","so",
                     "is","are","am","was","were",
                     "as","will","shall","should","can","could",
                     "this","that","these","those",
                     "with","not","then",
                     "myself","yourself","himself","herself","itself",
                     "yourselves","themselves" };


void Add(Word* head, char* w, int len) {
    if (len <= 1) return;
    char* p = *stopword;
    for (long unsigned int i = 0; i < sizeof(stopword) / sizeof(char*); i++, p++)
        if (strcmp(w, p) == 0)
            return;
    Word* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->w, w) == 0) {
            current->next->count++;
            return;
        }
        current = current->next;
    }
    Word* newWord = (Word*)malloc(sizeof(Word));
    if (newWord == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    newWord->w = (char*)malloc(sizeof(char) * (len + 1));
    if (newWord->w == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    strcpy(newWord->w, w);
    newWord->count = 1;
    newWord->next = NULL;
    current->next = newWord;
}

void Sort(Word* head) {
    Word* current = head->next;
    if (current == NULL) return;
    Word* tmp;
    while (current->next != NULL) {
        tmp = head;
        while ((tmp->next->count > current->next->count ||
            (tmp->next->count == current->next->count && strcmp(tmp->next->w, current->next->w) < 0)) &&
            tmp->next != current->next)
            tmp = tmp->next;
        if (tmp->next != current->next) {
            Word* tmp2 = current->next;
            current->next = tmp2->next;
            tmp2->next = tmp->next;
            tmp->next = tmp2;
        } else
            current = current->next;
    }
}

void Print(FILE* out, Word* node, int maxlen, int sum) {
    char ss[30];
    sprintf(ss, "%%5d %%%ds %%4d %%5.2f%%%%\n", maxlen);
    int i = 0;
    while (node != NULL) {
        fprintf(out, ss, ++i, node->w, node->count, node->count * 100.0 / sum);
        node = node->next;
    }
    fprintf(out, "total word count = %d\n", sum);
}

void DelTable(Word* node) {
    while (node != NULL) {
        Word* temp = node;
        node = node->next;
        free(temp->w);
        free(temp);
    }
}

int main(int argc, char* argv[ ]) {
    if (argc != 3) {
        printf("Usage: %s <inputfile> <outputfile>\n", argv[0]);
        exit(1);
    }
    FILE* in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Error for open %s.\n", argv[1]);
        exit(1);
    }
    FILE* out = fopen(argv[2], "w");
    if (out == NULL) {
        fprintf(stderr, "Error for writing to %s.\n", argv[2]);
        exit(1);
    }
    Word* head = (Word*)malloc(sizeof(Word));
    if (head == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    head->w = NULL;
    head->count = -1;
    head->next = NULL;
    char ch, * word = (char*)malloc(sizeof(char) * MAXLEN);
    int maxlen = 0, cnt = 0;
    if (word == NULL) {
        fprintf(stderr, "Error for malloc.\n");
        exit(1);
    }
    while ((ch = tolower(fgetc(in))) != EOF) {
        if (isalpha(ch)) {
            int i = 0;
            while (isalpha(ch)) {
                word[i++] = ch;
                ch = tolower(fgetc(in));
            }
            word[i] = '\0';
            Add(head, word, i);
            maxlen = i > maxlen ? i : maxlen;
            cnt++;
        }
    }
    Sort(head);
    Print(out, head->next, maxlen, cnt);
    DelTable(head);
    free(word);
    fclose(in);
    fclose(out);
    return 0;
}
