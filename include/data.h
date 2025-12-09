#pragma once
#include <stdio.h>
#include <stdbool.h>
typedef unsigned int u_int;

/**
 * @brief Структура, описывающая научную публикацию
 */

 
typedef struct {
    char title[256];
    char author_surname[256];
    char author_initials[16];
    char journal[256];
    u_int year;
    u_int volume;
    bool in_rinc;
    u_int pages;
    u_int citations;
} Publication;

typedef struct StackNode {
    Publication data;
    struct StackNode* next;
} StackNode;

typedef StackNode* Stack;

int read_publication_csv(FILE *file, Publication *p);

