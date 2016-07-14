#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct ListElmt_ {
  void *data;
  struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  ListElmt  *head;
  ListElmt  *tail;
} List;


/***********************
 * PUBLIC INTERFACE 
 ***********************/
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)
#endif
