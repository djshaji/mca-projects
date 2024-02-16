/*  Linked list
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct {
    int data ;

    /* Node 
    * We have taken this as void because we cannot 
    * define a struct within itself
    */ 
   void * next ;
} Node ;

typedef struct  {
    Node * head ;
} List ;

// function declarations
List * list_new () ;
void list_enter_data (List * list) ;
void list_append (List * list, int value) ;
void list_remove (List * list, int index) ;
void list_traverse (List * list);
void list_delete (List * list) ;

List * list_new () {
    return malloc (sizeof (List)) ;
}

void list_delete (List * list) {
    // delete all nodes within the list
    Node * temp = list -> head , * current = NULL;
    while (temp -> next != NULL) {        
        current = temp ;
        temp = temp -> next ;

        // free current pointer being iterated after pointing temp
        /// to next pointer in list
        free (current);
    }

    // free the list
    free (list);
}

void list_delete_data (List * list) {
    // delete one item from the list
    printf ("enter index to delete: \n");
    int index = -1 ;
    scanf ("%d", & index) ;
    if (index == -1)
        return ;  
    
    list_remove (list, index) ;
}

void list_append (List * list, int value) {    
    // append an item to the list
    Node * node = malloc (sizeof (Node));
    node -> data = value ;
    node -> next = NULL ;

    /*  Because we append the item to the end of the list,
        and there is no way to get to any specific point N in the 
        list directly, we have to traverse the entire list

        This has complexity O(n)
    */

    Node * temp = list -> head ;
   
    // list is empty
    if (list -> head == NULL) {
        list -> head = node ;
    } else {
        // keep on going from one to the next node until we reach the last
        // where next pointer is NULL
        while (temp -> next != NULL) {
            temp = temp -> next ;
        }

        // the last node in the list, assign it to the newly created node
        temp -> next = node ;
    }
}

void list_remove (List * list, int index) {
    // remove an item from a list at index n
    int i = 0 ; 
    Node * temp = list -> head ;
    Node * prev = NULL ;

    /*  Again, we have to traverse the entire list to find the item
        at index N
    */

    while (temp -> next != NULL) {
        if (i == index) {
            if (i == 0) {
                // if we delete first item in list, we have to update the 
                // pointer at the start of the list i.e. head
                list -> head = list -> head -> next ;                
            } else {
                /*  Since we are deleting in the middle, we have to 
                    "link" the previous pointer of the deleted node
                    with the "next" pointer. For this, we assign a prev node
                    pointer before assigning temp to the next node.
                */
                prev -> next = temp -> next ;
            }

            free (temp) ;
            printf ("deleted data at index %d\n", index);
            return ;
        }

        /*
        we assign a prev node pointer before assigning temp to the next node. */
        prev = temp ;

        temp = temp -> next ;
        i ++ ;
    }
}

void list_traverse (List * list) {
    Node * temp = list -> head ;
    int i = 0 ;
    while (temp -> next != NULL) {
        printf ("[data at %d]: %d\n", i, temp -> data) ;
        temp = temp -> next ;
        i ++ ;
    }

    
}

void list_enter_data (List * list) {
    int enter = 0 ;
    while (enter > -1) {
        printf ("enter data at index %d\n", enter) ;
        int data = -1 ;

        scanf ("%d", &data) ;
        if (data == -1) {
            return;
        }
        else
            enter ++ ;

        list_append (list, data) ;
    }

    
}

int main (int argc, char * agrv []) {
    List * list = list_new () ;
    list_enter_data (list) ;
    list_traverse (list) ;
    list_delete_data (list);
    list_traverse (list);

    list_delete (list) ;
}