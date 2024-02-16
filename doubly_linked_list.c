/*  Linked list
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data ;

    /* Node 
    * We have taken this as void because we cannot 
    * define a struct within itself
    */ 
   void * next ;
   void * prev ;
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
    node -> prev = NULL ;

    /*  Because we append the item to the end of the list,
        and there is no way to get to any specific point N in the 
        list directly, we have to traverse the entire list

        This has complexity O(n)
    */

    Node * temp = list -> head ;
    Node * current = NULL ;
   
    // list is empty
    if (list -> head == NULL) {
        list -> head = node ;
    } else {
        // keep on going from one to the next node until we reach the last
        // where next pointer is NULL
        while (temp -> next != NULL) {
            current = temp ;
            temp = temp -> next ;
        }

        // the last node in the list, assign it to the newly created node
        temp -> prev = current ;
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
                list -> head -> prev = NULL ;
            } else {              
                // this is the previous element
                Node * _next = temp -> next ;

                // this is the next element
                Node * _prev = temp -> prev; 

                // "link" the previous and next elements to each other
                _prev -> next = temp -> next;
                _next -> prev = temp -> prev;
            }

            free (temp) ;
            printf ("deleted data at index %d\n", index);
            return ;
        }

        temp = temp -> next ;
        i ++ ;
    }
}

void list_traverse (List * list) {
    Node * temp = list -> head, * last = NULL ;
    int i = 0 ;
    printf ("-------------| ↓ going down |-----------------\n");
    while (temp -> next != NULL) {
        Node * prev = temp -> prev ;
        printf ("↓ [data at %d]: %d\n", i, temp -> data) ;
        last = temp ; // this will be the last node when temp becomes NULL
        temp = temp -> next ;
        i ++ ;
    }

    temp = last ;
    i -- ;

    printf ("-------------| ↑ going up |-----------------\n");
    while (i > -1) {
        printf ("↑ [data at %d]: %d\n", i, temp -> data) ;
        temp = temp -> prev ;
        i -- ;
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