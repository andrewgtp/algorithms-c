/*
 * NOTES:
 *
 * sources: justin1534 and Hanson
 * 
 * we use the following nodes in this program:
 * head, tail
 * cur, cur_temp
 * do we also want an: x,y,z or a p,d,q to temp
 * cache nodes when doing sorting, searching?
 *
 * choose headers w/ standard function names (push,pop,etc. reserved for stack)
 *
 */

#include <stdio.h>
#include <stdlib.h>

const char *LINE = "----------------------------";

typedef struct _node{
  struct _node* next;
  int data;
} NODE;

NODE *node_new(int);
int list_insert_front(NODE **, int);
int list_insert_back(NODE **, int);

// TBD: combine these into one function:
// int list_delete(NODE **, int pos)
int list_delete_front(NODE **);
int list_delete_back(NODE **);
void list_print(NODE *);
NODE *list_reverse(NODE *);
void list_free(NODE *);
//NODE list_copy(NODE, void **);
void print_log_header(char *);
void example_basic();


NODE *node_new(int data) {
    NODE *new;
    new = malloc(sizeof(NODE));
    new->data = data;
    new->next = NULL;
    return new;
}

int list_insert_front(NODE **head, int data){

    NODE *new = node_new(data);

    // if head doesn't point to a node
    if (*head == NULL) {
        *head = new;

    // if head points to a node
    } else {
	new->next = *head;
	*head = new;
    }

    printf("Inserted %d to front of list.\n", new -> data);
    return 1;
}

// input node: head (but could be any node)
int list_insert_back(NODE **head, int data){

    NODE *new = node_new(data);
    
    // if list is not blank, add new node after current last node
    if (*head != NULL) {
        NODE *cur_tmp = *head;
    
        // set the cur_tmp point to the last node
        while(cur_tmp->next != NULL){
            cur_tmp = cur_tmp->next;
        }
        (cur_tmp)->next = new;

    // if list blank, set head point to new node
    } else {
        *head = new;
    }
    printf("Inserted %d to back of list.\n", new->data);
    return 1;
}

// delete first node in list
int list_delete_front(NODE **cur){

    if (*cur != NULL) {

        printf("Deleted %d from the front of list\n", (*cur)->data);
        *cur = (*cur)->next;
        return 1;
    }
    return 0;
}

// delete last node in the list
int list_delete_back(NODE **cur){

    NODE *cur_tmp;
    // If only one node in list
    if (*cur != NULL) {

	// If more than one node in list
	if ((*cur)->next != NULL) {

	    cur_tmp = *cur;
	    while(cur_tmp->next->next != NULL){
		cur_tmp = cur_tmp->next;
	    }
	    printf("Deleted %d from the back of list\n", cur_tmp->next->data);
	    free(cur_tmp->next);
	    cur_tmp->next = NULL;

	} else {

	    printf("Deleted %d from the back of list\n", (*cur)->data);
	    free(*cur);
	    *cur = NULL;

	}
	return 1;
    }
    return 0;
}

void list_free(NODE *head){

   NODE *tmp;

   while (head != NULL) {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

void list_print(NODE *head){

    printf("node traverse: ");
    if (head != NULL) {
	while(head != NULL) {
	    printf("%d ", head->data);
	    head = head->next;
	}
	printf("\n\n");
    } else {
        printf("EMPTY!\n\n");
    }
}

NODE *list_reverse(NODE *head) {

    // create local (temp) nodes to cache node pointers 
    // p(revious), c(urrent), n(next)
    NODE *p = NULL, *c = head, *n;

    while (c != NULL)
    {
        n = c->next; c->next = p;
        p = c; c = n;
    }
    return p; // == the new head
}

NODE *list_reverse_LONG_VERSION(NODE *head) {
    // create local (temp) nodes to cache node pointers 
    NODE *prev   = NULL;
    NODE *current = head;
    NODE *next;

    while (current != NULL)
    {
        next = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void print_log_header(char *msg) {
    printf("\n%s\n%s\n%s\n\n", LINE, msg, LINE);
}

void example_basic() {

    NODE *head;
    head = NULL;
    int check = 1;

    print_log_header("INITIAL LIST");

    list_print(head);

    print_log_header("FRONT INSERTS");

    check &= list_insert_front(&head, 12);
    list_print(head);
    
    check &= list_insert_front(&head, 11);
    list_print(head);
    
    check &= list_insert_front(&head, 10);
    list_print(head);

    print_log_header("BACK INSERTS");

    check &= list_insert_back(&head, 13);
    list_print(head);

    check &= list_insert_back(&head, 14);
    list_print(head);

    print_log_header("LIST REVERSE");
    head = list_reverse(head);
    list_print(head);

    print_log_header("FRONT DELETES");

    check &= list_delete_front(&head);
    list_print(head);
    
    print_log_header("BACK DELETES");

    check &= list_delete_back(&head);
    list_print(head);

    print_log_header("FRONT DELETES");

    check &= list_delete_back(&head);
    list_print(head);

    check &= list_delete_front(&head);
    list_print(head);

    check &= list_delete_front(&head);
    list_print(head);

    print_log_header("FREE LIST!");

    list_free(head);

    print_log_header("END LIST");

    list_print(head);

    if(check) {
        printf("Memory allocation and node deletion work normally.\n\n\n");
    } else {
        printf("Insert or delete function may have failed.\n\n\n");
    }
}

int main(void){
    example_basic();
    return 0;
}

