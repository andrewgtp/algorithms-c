
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.c"
#include "utils.c"


int main() {

   List *list;

   print_log_header("list_init");
   list_init(list, NULL);

   //list_ins_next(List *list, ListElmt *element, void **data);
   print_log_header("list_ins_next");

   //ListElmt *node =  NULL;

   ListElmt *node;
   int count = 4;
   for(int i = 0; i < count; i++) {
       if (i == 0) { 
           node = NULL;
           list_ins_next(list, node, i);
       } else {
           node = (ListElmt *) malloc(sizeof(node));
           node->data = i;
           node->next = NULL;
           list_ins_next(list, node, i);
       }

       printf("list->head (addr): %p\n", &list->head);
       printf("list->tail (addr): %p\n", &list->tail);
       printf("--------------------\n");
   }
   print_log_header("DONE!");

   //printf("list->head->data: %d\n", (*list)->head->data);
   //printf("list->tail->data: %d\n", node->data);

   print_log_header("list_print");
   //list_print(&list);
   list_print(list);
}
