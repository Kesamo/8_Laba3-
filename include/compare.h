#pragma once
#include "data.h"
#include <string.h>
#include <stdio.h>

int compare_asc(const Publication* p1, const Publication* p2);

int cmp_bool(bool p1, bool p2);

int cmp_int(u_int p1, u_int p2);

void reverse_stack(Stack* s);

int compare_desc(const Publication* p1, const Publication* p2);
