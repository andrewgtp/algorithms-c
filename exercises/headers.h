#ifndef HEADERS_H
#define HEADERS_H

/* linked-list element structure */
typedef struct ListElmt_ {

    void               *data;
    struct ListElmt_   *next;

} ListElmt;


/* linked list structure */
typedef struct List_ {

    int                size;
    int                (*match)(const void *key1, const void *key2);
    void               (*destroy)(void *data);
    ListElmt           *head;
    ListElmt           *tail;

} List;

int list_ins_next(List *list, ListElmt *element, const void *data);

#endif
