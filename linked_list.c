/*  Linked list
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data ;
    /* Node */ void * next ;
} Node ;

typedef struct  {
    /* data */
    Node * head ;
} List ;

// function declarations
List * list_new () ;
void list_enter_data (List * list) ;
void list_append (List * list, int value) ;
// void list_remove (List * list, int value) ;
void list_traverse (List * list);
// void list_delete (List * list) ;

List * list_new () {
    return malloc (sizeof (List)) ;
}

void list_append (List * list, int value) {
    Node * node = malloc (sizeof (Node));
    node -> data = value ;
    node -> next = NULL ;

    // list is empty
    if (list -> head == NULL) {
        list -> head = node ;
    } else {
        while (list -> head != NULL) {
            list -> head = list -> head -> next ;
        }

        list -> head -> next = node ;
    }
}

void list_traverse (List * list) {
    Node * temp = list -> head ;
    int i = 0 ;
    while (temp != NULL) {
        temp = temp -> next ;
        printf ("[data at %d]: %d\n", i, temp -> data) ;
        i ++ ;
    }
}

void list_enter_data (List * list) {
    int enter = 0 ;
    while (enter > -1) {
        printf ("enter data at index %d\n", enter) ;
        int data = -1 ;

        scanf ("%d", &data) ;
        if (data == -1)
            enter = -1 ;
        else
            enter ++ ;
        
        list_append (list, data) ;
    }
}

int main (int argc, char * agrv []) {
    List * list = list_new () ;
    list_enter_data (list) ;
    list_traverse (list) ;

    // list_delete (list) ;
}