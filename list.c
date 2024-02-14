#include <stdio.h>

/*	
 * Linked List
 * 
 * 
 * 
 */

typedef struct
{
 int count;
 int entry[100];
} List;

void insert (List * list) ;

void input (List * list) {
	for (int i = 0 ; i < 10 ; i ++) {
		printf ("enter number %d:\n", i);
		scanf ("%d", & list -> entry[i]) ;		
		list -> count ++ ;
	}
}

void traverse (List * list) {
	for (int i = 0; i < list -> count ; i ++) {
		printf ("Entry at position %d: %d\n", i, list -> entry [i]) ;
	}
}

int main (int argc, char * argv []) {
	List list ;
	input (& list) ;
	insert (&list) ;
	traverse (&list) ;
}

void insert (List * list) {
	printf ("insert element at: ") ;
	int element = 0, pos = 0;
	scanf ("%d", &pos) ;
	printf ("\nenter element: " );
	scanf ("%d", &element) ;
	printf ("\n") ;
	
	// shift elements to the right
	for (int i = list -> count ; i > pos - 1 ; i --) {
		list -> entry [i] = list -> entry [i - 1];
	}

	list -> entry [pos] = element;
}
