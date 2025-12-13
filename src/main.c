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
    puts("Инациализация стека");
    stack_init(&my_stack);

    puts("Добавление элементов");
    stack_push(&my_stack, &p);
    stack_push(&my_stack, &p1);
    stack_push(&my_stack, &p2);

    printf("Количество элементов в стэке: ");
    printf("%d\n",stack_size(my_stack));

    if (stack_empty(my_stack)) {
        printf("Стэк пуст\n");
    }
    else{
        printf("Стэк не пуст\n");
    }

    puts("Вывод стэка");
    show_stack_csv(my_stack);

    puts("Удаление элемента");
    stack_pop(&my_stack);

    puts("Вывод стэка после удаление первого элемента");
    show_stack_csv(my_stack);

    puts("Очистака стека и памяти");
    stack_clear(&my_stack);

    printf("Количество в стэке: ");
    printf("%d\n",stack_size(my_stack));

    puts("Проверка что выводит функция когда стэк пуст");
    show_stack_csv(my_stack);

    if (stack_empty(my_stack)) {
        printf("Стэк пуст\n");
    }
    else{
        printf("Стэк не пуст\n");
    }



}