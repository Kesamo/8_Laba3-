#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "data.h"
#include <stdlib.h>

void stack_push(Stack* s, const Publication* pub);

void stack_init(Stack* s);

void show_stack_csv(const StackNode* top);

void stack_pop(Stack* s);