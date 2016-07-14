#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    ListElmt *head;
    ListElmt *tail;
} List;

void list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    List linkedList;
    list_init(&linkedList);
    return 0;
}












