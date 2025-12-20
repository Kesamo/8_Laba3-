#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "stack.h"
#include "data.h"

/**
 * @brief 
 * 
 * @param str 
 * @param out 
 * @return int 1 - ошибка ввода 0 - функция выполненна коректно
 */

 int parse_uint(const char* str, u_int* out) {
    if (!str || !out) return 0;
    
    char* end;
    long val = strtol(str, &end, 10);
    
    if (*end != '\0') {
        return 0;
    }
    
    *out = (u_int)val;
    return 1;
}

/**
 * @brief Чтение из cmd и файла
 * 
 * @param file 
 * @param pub 
 * @return int 
 */

int read_publication_csv(FILE *file, Publication *pub){

    if (!file || !pub) return -1;

    char str[1024];
    if (fgets(str, sizeof(str), file) == NULL) {
        return 0;
    }

    str[strcspn(str, "\n")] = '\0';
    str[strcspn(str, "\r")] = '\0';

    char *token;

    token = strtok(str, ",");
    if(!token) return 0;
    snprintf(pub->title, sizeof(pub->title), "%s", token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    snprintf(pub->author_surname, sizeof(pub->author_surname), "%s", token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    snprintf(pub->author_initials, sizeof(pub->author_initials), "%s", token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    snprintf(pub->journal, sizeof(pub->journal), "%s", token);

    token = strtok(NULL, ",");
    if (!token || !parse_uint(token, &pub->year)) return 0;

    token = strtok(NULL, ",");
    if (!token || !parse_uint(token, &pub->volume)) return 0;

    token = strtok(NULL, ",");
    if (!token) return 0;
    pub->in_rinc = (strcmp(token, "true") == 0);

    token = strtok(NULL, ",");
    if (!token || !parse_uint(token, &pub->pages)) return 0;

    token = strtok(NULL, ",");
    if (!token || !parse_uint(token, &pub->citations)) return 0;

    return 1;

}


/**
 * @brief Сохраняет стек в csv
 * @param file
 * @param s
 * @return 0 — успех, 1 — ошибка
 */

int save_stack_to_csv(Stack s) {

    FILE* file = fopen("output.csv", "w");

    if (!file) return 1;

    Stack temp = NULL;
    Publication item;

    while (s != NULL) {
        item = s->data;

        fprintf(file, "%s,%s,%s,%s,%u,%u,%s,%u,%u\n",
                item.title,
                item.author_surname,
                item.author_initials,
                item.journal,
                item.year,
                item.volume,
                item.in_rinc ? "true" : "false",
                item.pages,
                item.citations);

        s = s->next;
    }

    fclose(file);
    return 0;
}

/**
 * @brief Вывод и сохранение фала в формате сьв
 * 
 * @param top 
 * @param output 
 */

void show_stack_csv(Stack top, FILE* output){
    if (stack_empty(top)) {
        puts("Стэк пуст");
        return;
    }
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Stack helper;
    stack_init(&helper);
    Publication top_stack;

    FILE* out = (output) ? output : stdout;

    while (!stack_empty(top))
    {
        stack_peek(top,&top_stack);
        fprintf(out,"%s,%s,%s,%s,%u,%u,%s,%u,%u\n",
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
