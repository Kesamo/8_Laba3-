#pragma once
#include "stack.h"
#include "data.h"

/**
 * @brief Сортировка слиянием для стека (реализованного как список)
 * @param head — указатель на вершину стека
 * @param cmp — компаратор: 
 *
 */
void stack_merge_sort(Stack* s);