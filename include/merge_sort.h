#pragma once
#include "stack.h"
#include "data.h"
typedef int (*Comparator)(const Publication*, const Publication*);

/**
 * @brief Сортировка слиянием для стека (реализованного как список)
 * @param head — указатель на вершину стека
 * @param cmp — компаратор: 
 *
 */
void stack_merge_sort(Stack* s, Comparator cmp);