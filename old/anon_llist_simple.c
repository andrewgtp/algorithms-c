#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************
 * iBitchin.com
 * CONFIDENTIAL - LEVEL RED
 ******************************/

typedef struct _employee{
    char name[32];
    unsigned char age;
} Employee;

void displayEmployee(Employee* employee) {
    printf("%s\t\%d\n", employee->name, employee->age);
}

int compareEmployee(Employee *e1, Employee *e2) {
    return strcmp(e1->name, e2->name);
}

typedef void(*DISPLAY)(void *);
typedef int(*COMPARE)(void*, void*);

typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
} ListElmt;

typedef struct LinkedList_ {
    ListElmt *head;
    ListElmt *tail;
    ListElmt *current;
} List;

void list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

}

void addHead(List *list, void* data) {
    ListElmt *node = (ListElmt*) malloc(sizeof(node));
    node->data = data;
    if (list->head == NULL) {
        list->tail = node; // new_element
        node->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
}

void addTail(List *list, void* data) {
    ListElmt *node = (ListElmt*) malloc(sizeof(node));
    node->data = data;
    if (list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

void delete(List *list, ListElmt *node) {
    if (node == list->head) {
        if (list->head->next == NULL) {
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        ListElmt *tmp = list->head;
        while (tmp != NULL && tmp->next != node) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
           tmp->next = node->next;
        }
    }
    free(node);
}

ListElmt *getListElmt(List *list, COMPARE compare , void* data) {
    ListElmt *node = list->head;
    while (node != NULL) {
        if (compare(node->data, data) == 0) { 
            return node;  
        }
        node = node->next;
    }
    return NULL;

}

void displayList(List *list, DISPLAY display) {
    printf("\nLunked List\n");
    ListElmt *current = list->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}


int main() {
    List linkedList;
     
    Employee *andrew = (Employee*) malloc(sizeof(Employee));
    strcpy(andrew->name, "Andrew");
    andrew->age=18;

    Employee *richard = (Employee*) malloc(sizeof(Employee));
    strcpy(richard->name, "Richard");
    richard->age=18;

    Employee *barry = (Employee*) malloc(sizeof(Employee));
    strcpy(barry->name, "Barry");
    barry->age=18;

    Employee *sullivan = (Employee*) malloc(sizeof(Employee));
    strcpy(sullivan->name, "Sullivan");
    sullivan->age=18;

    list_init(&linkedList);
    printf("List before:\n");
    displayList(&linkedList, (DISPLAY)displayEmployee);

    addHead(&linkedList, andrew);
    addHead(&linkedList, richard);

    printf("List after:\n");
    displayList(&linkedList, (DISPLAY)displayEmployee);

    addTail(&linkedList, barry);
    addTail(&linkedList, sullivan);

    printf("List after:\n");
    displayList(&linkedList, (DISPLAY)displayEmployee);

    //ListElmt *node = getListElmt(&linkedList,
    //          (int (*)(void*, void*))compareEmployee, richard);
   // delete(&linkedList, node);

    //printf("List after delete:\n");
    //displayList(&linkedList, (DISPLAY)displayEmployee);

    
    return 0;
}
