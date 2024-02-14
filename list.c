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
	traverse (&list) ;
}
