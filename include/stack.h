#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "data.h"
#include <stdlib.h>

void stack_push(Stack* s, const Publication* pub);

void stack_init(Stack* s);

void show_stack_csv(const Stack top);

int stack_pop(Stack* s);

int stack_peek(Stack s, Publication* out_pub);

int stack_clear(Stack *s);

size_t stack_size(Stack s);

bool stack_empty(Stack s);