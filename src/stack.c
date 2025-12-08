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

void show_stack_csv(const StackNode* top) {
    const StackNode* current = top;
    while (current != NULL) {
        printf("%s,%s,%s,%s,%u,%u,%s,%u,%u\n",
            current->data.title,
            current->data.author_surname,
            current->data.author_initials,
            current->data.journal,
            current->data.year,
            current->data.volume,
            current->data.in_rinc ? "true" : "false",
            current->data.pages,
            current->data.citations
        );
        current = current->next;
    }
}


/**
 * @brief 
 * 
 * @param s 
 */

void stack_pop(Stack* s) {
    if (*s == NULL) {
        return;
    }

    StackNode* old_top = *s;
    *s = (*s)->next;

    printf("Deleted: %s,%s,%s,%s,%u,%u,%s,%u,%u\n",
        old_top->data.title,
        old_top->data.author_surname,
        old_top->data.author_initials,
        old_top->data.journal,
        old_top->data.year,
        old_top->data.volume,
        old_top->data.in_rinc ? "true" : "false",
        old_top->data.pages,
        old_top->data.citations
    );

    free(old_top);
}
