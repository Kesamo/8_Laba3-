#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

/**
 * @brief Добавление элемента в начало
 * 
 * @param s 
 * @param pub 
 */

void stack_push(Stack* s, const Publication* pub) {
    StackNode* node = malloc(sizeof(StackNode));
    node->data = *pub;
    node->next = *s;
    *s = node;
}

/**
 * @brief Инициализация
 * 
 * @param s 
 */

void stack_init(Stack* s) {
    *s = NULL;
}

/**
 * @brief 
 * 
 * @param top 
 */


void show_stack_csv(Stack top){
    if (stack_empty(top)) {
        printf("Стэк пуст\n");
        return;
    }
    Stack helper;
    stack_init(&helper);
    Publication top_stack;

    while (!stack_empty(top))
    {
        stack_peek(top,&top_stack);
        printf("%s,%s,%s,%s,%u,%u,%s,%u,%u\n",
            top_stack.title,
            top_stack.author_surname,
            top_stack.author_initials,
            top_stack.journal,
            top_stack.year,
            top_stack.volume,
            top_stack.in_rinc ? "true" : "false",
            top_stack.pages,
            top_stack.citations
        );
        stack_pop(&top);
        stack_push(&helper,&top_stack);
    }
    while (!stack_empty(helper))
    {
        stack_peek(helper,&top_stack);
        stack_pop(&helper);
        stack_push(&top,&top_stack);
    }
    
}

/**
 * @brief 
 * 
 * @param s 
 */

int stack_pop(Stack* s) {
    if (stack_empty(*s)) {
        printf("Стэк пуст\n");
        return 1;
    }

    StackNode* old_top = *s;
    *s = (*s)->next;

    free(old_top);
    return 0;
}



bool stack_empty(Stack s) {
    return s == NULL;
}


u_int stack_size(Stack s) { 
    u_int count = 0;
    Stack helper;
    stack_init(&helper);
    Publication top_stack;
    while (!stack_empty(s)) {
        stack_peek(s,&top_stack);
        stack_pop(&s);
        stack_push(&helper,&top_stack);
        count++;
    }
    while (!stack_empty(helper))
    {
        stack_peek(helper,&top_stack);
        stack_pop(&helper);
        stack_push(&s,&top_stack);
    }
    return count;
}

int stack_peek(Stack s, Publication* out_pub) {
    if (stack_empty(s)) return 0;
    *out_pub = s->data;
    return 1;
}




int stack_clear(Stack* s){
    int check = 0;
    if (s == NULL){
        printf("Ошибка: передан нулевой указатель на стек\n");
        return 1;
    }
    while(*s != NULL){
        check = stack_pop(s);
        if(check != 0){
            return check;
        }
    }
    printf("Стэк очищен\n");
    return 0;

}


int stack_peek_at(Stack* main_stack, u_int index, Publication* out_pub) {
    if (!main_stack || !out_pub) return 1;

    StackNode* temp;
    stack_init(&temp);
    Publication item;
    u_int i = 0;
    int found = 0;

    while (!stack_empty(*main_stack) && i <= index) {
        stack_peek(*main_stack, &item);
        stack_pop(main_stack);
        
        if (i == index) {
            *out_pub = item;
            found = 1;
        }

        stack_push(&temp, &item);
        i++;
    }

    while (!stack_empty(temp)) {
        stack_peek(temp, &item);
        stack_pop(&temp);
        stack_push(main_stack, &item);
    }

    if (found){
        return 0;
    }
    else{
        return 1;
    }
}

Stack* get_top(Stack* s) {
    return s;
}

Stack get_bottom(Stack s) {
    if (!s) return NULL;
    while (s->next != NULL) {
        s = s->next;
    }
    return s; 
}


void array_to_stack(Stack* s, const Publication* arr, u_int n) {
    if (!s || !arr) return;

    stack_clear(s);

    for (u_int i = n; i > 0; i--) {
        stack_push(s, &arr[i - 1]);
    }
}

u_int stack_to_array(Stack* s, Publication* arr, u_int max_size) {
    u_int count = 0;
    while (!stack_empty(*s) && count < max_size) {
        stack_peek(*s, &arr[count]);
        stack_pop(s);
        count++;
    }
    return count;
}

