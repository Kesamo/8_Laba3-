#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "flag.h"
#include "stack.h"
#include "table.h"
#include "insertion_sort.h"
#include "generate.h"
#include "compare.h" 


int main (int argc, char* argv[]){
    Args args;

    if(!parse_args(argc,argv,&args)){
        return 1;
    }

    if(args.help){
        print_help();
        free_args(&args);
        return 0;
    }

    if(args.sort){
        Stack stack;
        stack_init(&stack);
        FILE* in = stdin;

        if(args.input_csv){
            in = fopen(args.input_file, "r");
            if(!in){
                fprintf(stderr,"Не удалось открыть входной файл\n");
                free_args(&args);
                return 1;
            }
        }

        Publication pub;
        while (read_publication_csv(in, &pub) == 1) {
            stack_push(&stack, &pub);
        }

        if (args.input_csv) {
            fclose(in);
        }

        insertion_sort(&stack);

        if (strcmp(args.flag, "desc") == 0){
            reverse_stack(&stack);
        }

         FILE* out = stdout;
        if (args.output_csv) {
            out = fopen(args.out_file, "w");
            if (!out) {
                fprintf(stderr,"Не удалось открыть файл для записи\n");
                stack_clear(&stack);
                free_args(&args);
                return 1;
            }
        }

        show_stack_csv(stack,out);

        if (args.output_csv) {
            fclose(out);
        }

        stack_clear(&stack);
        free_args(&args);
        return 0;

    }

    if(args.print){
        Stack stack;
        stack_init(&stack);
        FILE* in = stdin;

        if(args.input_csv){
            in = fopen(args.input_file,"r");
            if(!in){
                fprintf(stderr,"Не удалось открыть входной файл\n");
                free_args(&args);
                return 1;
            }
            else{
                char file_name [256];
                printf("Введите имя файла: ");
                if(fgets(file_name, sizeof(file_name), stdin) == NULL) {
                    free_args(&args);
                    return 1;
                }
                in = fopen(file_name,"r");
                if(!in){
                    fprintf(stderr,"Не удалось открыть входной файл\n");
                    free_args(&args);
                    return 1;
                }
            }
        }

        Publication pub;
        while (read_publication_csv(in,&pub) == 1){
            stack_push(&stack,&pub);
        }
        fclose(in);

        FILE* out = stdout;
            if(args.output_csv){
                out = fopen(args.out_file,"w");
                if (!out) {
                    fprintf(stderr,"Не удалось открыть файл для записи\n");
                    stack_clear(&stack);
                    free_args(&args);
                    return 1;
                }
            }
            
            print_table(stack,out);

            if (args.output_csv) {
            fclose(out);
            }

            stack_clear(&stack);
            free_args(&args);
            return 0;

    }

    if(args.generat){
        Stack stack;
        stack_init(&stack);
        FILE* out = stdout;
        init_random();
        stack_generate(&stack,args.num);

        if (args.output_csv) {
            out = fopen(args.out_file, "w");
            if (!out) {
                fprintf(stderr,"Не удалось открыть файл для записи");
                stack_clear(&stack);
                free_args(&args);
                return 1;
            }
        }

        show_stack_csv(stack,out);

        if (args.output_csv) {
            fclose(out);
        }

        stack_clear(&stack);
        free_args(&args);
        return 0;


    }

}