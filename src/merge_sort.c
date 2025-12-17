#include "merge_sort.h"
#include "compare.h"

void split_stack_into_two(Stack* s, Stack* front, Stack* back) {
    stack_init(front);
    stack_init(back);

    if (!s || stack_empty(*s)) {
        return;
    }

    u_int size = stack_size(*s);
    u_int mid = size / 2;

    Stack temp = NULL;
    Publication item;

    while (!stack_empty(*s)) {
        stack_peek(*s, &item);
        stack_pop(s);
        stack_push(&temp, &item);
    }

    Stack back_temp = NULL;
    for (u_int i = 0; i < size - mid; i++) {
        stack_peek(temp, &item);
        stack_pop(&temp);
        stack_push(&back_temp, &item);
    }
    while (!stack_empty(back_temp)) {
        stack_peek(back_temp, &item);
        stack_pop(&back_temp);
        stack_push(back, &item);
    }

    Stack front_temp = NULL;
    while (!stack_empty(temp)) {
        stack_peek(temp, &item);
        stack_pop(&temp);
        stack_push(&front_temp, &item);
    }
    while (!stack_empty(front_temp)) {
        stack_peek(front_temp, &item);
        stack_pop(&front_temp);
        stack_push(front, &item);
    }
}

Stack stack_merge_sorted(Stack* left, Stack* right) {
    Stack result;
    stack_init(&result);
    Publication left_item;
    Publication right_item;

    while (!stack_empty(*left) && !stack_empty(*right)) {
        stack_peek(*left, &left_item);
        stack_peek(*right, &right_item);

        if (compare_publications(&left_item, &right_item) <= 0) {
            stack_pop(left);
            stack_push(&result, &left_item);
        } else {
            stack_pop(right);
            stack_push(&result, &right_item);
        }
    }

    while (!stack_empty(*left)) {
        stack_peek(*left, &left_item);
        stack_pop(left);
        stack_push(&result, &left_item);
    }

    while (!stack_empty(*right)) {
        stack_peek(*right, &right_item);
        stack_pop(right);
        stack_push(&result, &right_item);
    }

    Stack helper;
    stack_init(&helper);
    Publication item;
    while (!stack_empty(result)) {
        stack_peek(result, &item);
        stack_pop(&result);
        stack_push(&helper, &item);
    }

    return helper;
}

void stack_merge_sort(Stack* s) {
    if (!s || stack_empty(*s) || stack_size(*s) <= 1) {
        return;
    }

    Stack front;
    stack_init(&front);
    Stack back;
    stack_init(&back); 

    split_stack_into_two(s, &front, &back);

    stack_merge_sort(&front);
    stack_merge_sort(&back);

    Stack merged = stack_merge_sorted(&front, &back);

    stack_clear(s);
    *s = merged;
}