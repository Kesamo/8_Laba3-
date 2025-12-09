#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include "data.h"
#include "stack.h"

int main (){

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Publication p;

    read_publication_csv(stdin,&p);

    Publication p1 = {"ИИ", "Иванов", "А.Б.", "Журнал науки", 2020, 12, true, 25, 42};
    Publication p2 = {"Кванты", "Петров", "К.С.", "Физика", 2021, 5, false, 10, 8};


    Stack my_stack;
    stack_init(&my_stack);

    stack_push(&my_stack, &p1);
    stack_push(&my_stack, &p2);

    show_stack_csv(my_stack);

    stack_pop(&my_stack);

    show_stack_csv(my_stack);

}