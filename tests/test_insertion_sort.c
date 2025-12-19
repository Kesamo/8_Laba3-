#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "insertion_sort.h"

void test_insertion_sort() {
    Stack s;
    stack_init(&s);

    Publication p1 = {"Whisper", "Матвей", "A.Р.", "Отношения", 2020, 1, true, 10, 5};
    Publication p2 = {"ИИ", "Иванов", "А.Б.", "Журнал науки", 2020, 12, true, 25, 42};
    Publication p3 = {"Кванты", "Сноров", "К.С.", "Физика", 2021, 5, false, 16, 6};

    stack_push(&s, &p1);
    stack_push(&s, &p2);
    stack_push(&s, &p3);

    insertion_sort(&s);

    Publication out;

    assert(stack_peek(s, &out) == 1);
    assert(strcmp(out.title, "Whisper") == 0);  
    stack_pop(&s);

    assert(stack_peek(s, &out) == 1);
    assert(strcmp(out.title, "ИИ") == 0);
    stack_pop(&s);

    assert(stack_peek(s, &out) == 1);
    assert(strcmp(out.title, "Кванты") == 0);
    stack_pop(&s);

    assert(stack_empty(s) == true);
    stack_clear(&s);

    puts("test_insertion_sort: OK");
}

int main() {
    test_insertion_sort();
    return 0;
}