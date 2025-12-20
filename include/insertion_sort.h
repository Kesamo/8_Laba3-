#pragma once
#include "data.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
typedef int (*Comparator)(const Publication*, const Publication*);

void insertion_sort(Stack* my_stack , Comparator cmp);