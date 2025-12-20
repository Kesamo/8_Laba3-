#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flag.h"

/**
 * @brief Вывод help
 * 
 */

void print_help(void) {
    puts("\t-h, --help");
    puts("\t-g, --generate=N");
    puts("\t-s, --sort");
    puts("\t-t, --type=TYPE");
    puts("\t-i, --in=FILE");
    puts("\t-o, --out=FILE");
    puts("\t-p, --print");
}

/**
 * @brief  Парсит аргументы командной строки и заполняет структуру Args.
 * 
 * @param argc 
 * @param argv 
 * @param args 
 * @return int 
 */

int parse_args(int argc, char* argv[], Args* args){
    args->out_file = NULL;
    args->input_file = NULL;
    args->flag = "asc";
    args->sort = false;
    args->help = false;
    args->input_csv = false;
    args->output_csv = false;
    args->print = false;
    args->generat = false;

    for(u_int i = 1; i < (u_int)argc; ++i){
        char* arg = argv[i];

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0){
            args->help = true;
        }
        else if (strcmp(arg, "-s") == 0 || strcmp(arg, "--sort") == 0){
            args->sort = true;
        }
        else if (strcmp(arg, "-p") == 0 || strcmp(arg,"--print") == 0){
            args->print = true;
        }
        else if (strncmp(arg, "--out=", 6) == 0 || strncmp(arg, "-o",2) == 0){
            args->output_csv = true;
            char* s = NULL;
            if(strncmp(arg, "--out=", 6) == 0){
                s = arg + 6;
            }
            else if(strncmp(arg, "-o", 2) == 0 && i+1 < argc){
                s = argv[++i];
            }
            else{
                fprintf(stderr, "Ошибка флага");
                return 1;
            }
            args->out_file = s;
        }
        else if(strncmp(arg, "-t", 2) == 0 || strncmp(arg, "--type=", 7) == 0){
            char* s = NULL;
            if(strncmp(arg, "--type=", 7) == 0){
                s = arg + 7;
            }
            else if(strncmp(arg, "-t", 2) == 0 && i+1 < argc){
                s = argv[++i];
            }
            else{
                fprintf(stderr, "Ошибка флага");
                return 1;
            }
            args->flag = strdup(s);
        }
        else if(strncmp(arg, "-i", 2) == 0 || strncmp(arg, "--in=", 5) == 0){
            args->input_csv = true;
            char* s = NULL;
            if(strncmp(arg, "--in=", 5) == 0){
                s = arg + 5;
            }
            else if(strncmp(arg, "-i", 2) == 0 && i+1 < argc){
                s = argv[++i];
            }
            else{
                fprintf(stderr, "Ошибка флага");
                return 1;
            }
            args->input_file = strdup(s);
        }
        else if(strncmp(arg, "-g",2) == 0 || strncmp(arg, "--generate=", 11) == 0){
            args->generat = true;
            char* value = NULL;
            if(strncmp(arg, "--generate=", 11) == 0){
                value = arg + 11;
            }
            else if(strncmp(arg, "-g", 2) == 0 && i+1 < argc){
                value = argv[++i];
            }
            else{
                fprintf(stderr, "Ошибка флага");
                return 1;
            }
            parse_uint(value,&args->num); 
        }
        else {
            fprintf(stderr, "Неизвестный аргумент: %s\n", arg);
            print_help();
            return 1;
        }
        
    }
    return 0;
}
    
/**
 * @brief Очистка памяти
 * 
 * @param args 
 */

void free_args(Args* args) {
    if (args) {
        free(args->out_file);
        free(args->input_file);
        free(args->flag);
    }
}

