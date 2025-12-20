#include "table.h"
#include <string.h>
#include <stdio.h>
#include <windows.h>

static void print_padded(FILE* f, const char* text, u_int field_width) {
    if (!f) return;
    if (!text) text = "";
    u_int char_len = strlen(text);
    u_int print_len = (char_len > field_width) ? field_width : char_len;

    const char* p = text;
    u_int printed_chars = 0;
    while (*p && printed_chars < print_len) {
        if ((*p & 0x80) == 0) {
            fputc(*p++, f);
        } else if ((*p & 0xE0) == 0xC0) {
            fputc(*p++, f); fputc(*p++, f);
        } else if ((*p & 0xF0) == 0xE0) {
            fputc(*p++, f); fputc(*p++, f); fputc(*p++, f);
        } else if ((*p & 0xF8) == 0xF0) {
            fputc(*p++, f); fputc(*p++, f); fputc(*p++, f); fputc(*p++, f);
        } else {
            fputc(*p++, f);
        }
        printed_chars++;
    }

    for (u_int i = printed_chars; i < field_width; i++) {
        fputc(' ', f);
    }
}



void print_table(Stack stack, FILE* output_file) {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    if (!output_file) return;

    const u_int title = 30;
    const u_int autor = 20;
    const u_int autor_init = 10;
    const u_int jornal = 25;
    const u_int year = 6;
    const u_int volume = 6;
    const u_int rinc = 6;
    const u_int pages = 8;
    const u_int citations = 10;

    print_padded(output_file, "Название", title);
    print_padded(output_file, "Автор", autor);
    print_padded(output_file, "Инициалы", autor_init);
    print_padded(output_file, "Журнал", jornal);
    print_padded(output_file, "Год", year);
    print_padded(output_file, "Том", volume);
    print_padded(output_file, "РИНЦ", rinc);
    print_padded(output_file, "Стр.", pages);
    fprintf(output_file, "%-*s\n", (int)citations, "Цитир.");

    u_int total = title + autor + autor_init + jornal + year + volume + rinc + pages + citations;
    for (u_int i = 0; i < total; i++) fputc('-', output_file);
    fputc('\n', output_file);

    Stack current = stack;
    while (current) {
        print_padded(output_file, current->data.title, title);
        print_padded(output_file, current->data.author_surname, autor);
        print_padded(output_file, current->data.author_initials, autor_init);
        print_padded(output_file, current->data.journal, jornal);
        fprintf(output_file, "%-*u", (int)year, current->data.year);
        fprintf(output_file, "%-*u", (int)volume, current->data.volume);
        print_padded(output_file, current->data.in_rinc ? "ДА" : "НЕТ", rinc);
        fprintf(output_file, "%-*u", (int)pages, current->data.pages);
        fprintf(output_file, "%-*u\n", (int)citations, current->data.citations);
        current = current->next;
    }
}