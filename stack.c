#include <stdio.h>

#define N 10
typedef struct stack {
    int array [N] ;
    int top ;
} Stack ;

void push (Stack * stack, int value) ;
void pop (Stack * stack);
int peek (Stack * stack) ;
void traverse (Stack * stack) ;

void push (Stack * stack, int value) {
    if (stack -> top == N - 1) {
        printf ("stack is full\n");
        return ;
    }

    stack -> array [stack -> top] = value ;
    stack -> top ++ ;
}

void pop (Stack * stack) {
    stack -> top -- ;
}

int peek (Stack * stack) {
    return stack -> array [stack -> top - 1] ;
}

void traverse (Stack * stack) {
    for (int i = 0 ; i < stack -> top ; i ++) {
        printf ("value at %d: %d\n", i, stack -> array [i]) ;
    }
}

int main (int argc, char * argv []) {
    int value = 0, i = 0 ;
    Stack stack ;
    stack.top = 0 ;
    while (1) {
        printf ("enter value at %d\n", i) ;
        scanf ("%d", &value) ;

        if (value == -1) 
            break ;
        
        push (& stack, value);
        i++ ;
    }

    traverse (& stack);
    printf ("popping ...\n") ;
    pop (& stack) ;

    traverse (& stack);
    printf ("peek: %d\n", peek (&stack));
}