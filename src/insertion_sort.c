#include "insertion_sort.h"
#include "compare.h"


void insertion_sort(Stack* my_stack){
    Stack helper;
    stack_init(&helper);
    Publication current;
    Publication top_helper;

    while (!stack_empty(*my_stack))
    {
        stack_peek(*my_stack,&current);
        stack_pop(my_stack);

        while(!stack_empty(helper)){
            stack_peek(helper,&top_helper);
            if (compare_publications(&top_helper,&current) <= 0){
                break;
            }

            stack_pop(&helper);
            stack_push(my_stack,&top_helper);
        }

        stack_push(&helper,&current);
    }

     while (!stack_empty(helper)) {
        stack_peek(helper, &top_helper);
        stack_pop(&helper);
        stack_push(my_stack, &top_helper);
    }
    
}