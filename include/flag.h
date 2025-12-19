#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"
typedef unsigned int u_int;

typedef struct {
    char* out_file;
    char* input_file;
    char* flag;
    bool sort;
    bool help;
    bool input_csv;
    bool output_csv;
    bool print;
    bool generat;
    u_int num;
} Args;


void print_help();
int parse_args(int argc, char* argv[], Args* args);
void free_args(Args* args);
