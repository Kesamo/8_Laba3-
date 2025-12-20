#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "stack.h"
#include "generate.h"

/**
 * @brief Добавление элемента в начало
 * 
 * @param s 
 * @param pub 
 */

void stack_push(Stack* s, const Publication* pub) {
    StackNode* node = malloc(sizeof(StackNode));
    if(!node){
        puts("Ошибка выделения памяти");
        return;
    }
    node->data = *pub;
    node->next = *s;
    *s = node;
}

/**
 * @brief Инициализация сэка
 * 
 * @param s 
 */

void stack_init(Stack* s) {
    *s = NULL;
}

/**
 * @brief Удаление верхнего элемента из стека
 * 
 * @param s 
 * @return int 
 */

int stack_pop(Stack* s) {
    if (stack_empty(*s)) {
        puts("Стэк пуст\n");
        return 1;
    }

    StackNode* old_top = *s;
    *s = (*s)->next;

    free(old_top);
    return 0;
}

/**
 * @brief Проверка пустой стек или нет
 * 
 * @param s 
 * @return true 
 * @return false 
 */

bool stack_empty(Stack s) {
    return s == NULL;
}

/**
 * @brief Функция возвращает количество элементов в стеке
 * 
 * @param s 
 * @return u_int 
 */

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

/**
 * @brief Вытаскивает верхний элемент из стека
 * 
 * @param s 
 * @param out_pub 
 * @return int 
 */

int stack_peek(Stack s, Publication* out_pub) {
    if (stack_empty(s)) return 0;
    *out_pub = s->data;
    return 1;
}

/**
 * @brief Очищант стек
 * 
 * @param s 
 * @return int 
 */

int stack_clear(Stack* s){
    int check = 0;
    if (s == NULL){
        puts("Ошибка: передан нулевой указатель на стек\n");
        return 1;
    }
    while(*s != NULL){
        check = stack_pop(s);
        if(check != 0){
            return check;
        }
    }
    return 0;

}

/**
 * @brief Вытаскивет элемент по индексу
 * 
 * @param main_stack 
 * @param index 
 * @param out_pub 
 * @return int 
 */

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

/**
 * @brief Возвращает указатель на вершину
 * 
 * @param s 
 * @return Stack* 
 */

Stack* get_top(Stack* s) {
    return s;
}

/**
 * @brief Возвращает указатель на последний узел стека
 * 
 * @param s 
 * @return Stack 
 */

Stack get_bottom(Stack s) {
    if (!s) return NULL;
    while (s->next != NULL) {
        s = s->next;
    }
    return s; 
}

/**
 * @brief Из масива в стэк
 * 
 * @param s 
 * @param arr 
 * @param n 
 */

void array_to_stack(Stack* s, const Publication* arr, u_int n) {
    if (!s || !arr) return;

    stack_clear(s);

    for (u_int i = n; i > 0; i--) {
        stack_push(s, &arr[i - 1]);
    }
}

/**
 * @brief Из стека в масив
 * 
 * @param s 
 * @param arr 
 * @param max_size 
 */

void stack_to_array(Stack* s, Publication* arr, u_int max_size) {
    u_int count = 0;
    while (!stack_empty(*s) && count < max_size) {
        stack_peek(*s, &arr[count]);
        stack_pop(s);
        count++;
    }
}

/**
 * @brief генерирует случайные данные в соответствии со схемой данных
 * 
 * @param s 
 * @param n 
 */

void stack_generate(Stack* s, u_int n) {
    if (!s) return;

    Publication pub;
    for (u_int i = 0; i < n; i++) {
        generate(&pub);
        stack_push(s, &pub);
    }
}

/**
 * @brief Переварачиает стэк
 * 
 * @param s 
 */

void reverse_stack(Stack* s) {
    if (!s) return;
    
    Stack helper;
    stack_init(&helper);
    Publication top_stack;

    while (!stack_empty(*s)) {
        stack_peek(*s, &top_stack);
        stack_pop(s);
        stack_push(&helper, &top_stack);
    }
    *s = helper;
}

/**
 * @brief Удаление элемента по индексу
 * 
 * @param s 
 * @param index 
 * @return int 
 */

int stack_pop_at(Stack* s, u_int index) {
    if (!s) return 0;

    Stack help1;
    stack_init(&help1);
    Stack help2 ;
    stack_init(&help2);
    Publication item;

    while (!stack_empty(*s)) {
        stack_peek(*s, &item);
        stack_pop(s);
        stack_push(&help1, &item);
    }

    u_int pos = 0;
    while (!stack_empty(help1)) {
        stack_peek(help1, &item);
        stack_pop(&help1);
        if (pos != index) {
            stack_push(&help2, &item);
        }
        pos++;
    }

    while (!stack_empty(help2)) {
        stack_peek(help2, &item);
        stack_pop(&help2);
        stack_push(s, &item);
    }

    return 1;
}

int stack_push_at(Stack* s, u_int index, const Publication* pub) {
    if (!s || !pub) return 0;

    Stack help1;
    stack_init(&help1);
    Stack help2;
    stack_init(&help2);
    Publication item;

    while (!stack_empty(*s)) {
        stack_peek(*s, &item);
        stack_pop(s);
        stack_push(&help1, &item);
    }

    u_int pos = 0;
    while (!stack_empty(help1) || (pos == index && stack_empty(help1))) {
        if (pos == index) {
            stack_push(&help2, pub);
            if (stack_empty(help1)) break;
        }
        if (!stack_empty(help1)) {
            stack_peek(help1, &item);
            stack_pop(&help1);
            stack_push(&help2, &item);
        }
        pos++;
    }

    while (!stack_empty(help2)) {
        stack_peek(help2, &item);
        stack_pop(&help2);
        stack_push(s, &item);
    }

    return 1;
}