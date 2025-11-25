#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    panel,
    brick,
    monolith
} HouseType;

/**
 * @brief Структура, описывающая многоквартирный дом
 */

typedef struct {
    char builder[256];
    char district[256];
    HouseType type;
    int build_year;
    bool has_elevator;
    bool has_chute;
    int apartments_count;
    int floors_count;
    double avg_area;
} House;