#include "generate.h"

char* titles[] = {
    "ZOV", "ИИ","Алгоритмы", "Кибербезопасность",
    "Блокчейн", "Робототехника", "Машинное обучение"
};

char* surnames[] = {
    "ZOV", "Петров", "Сидоров", "Смирнов",
    "Волков", "Морозов", "Новиков", "Лебедев"
};

char* initials[] = {
    "ZOV.", "А.Б", "В.Г", "Д.Е", "Ё.Ж",
    "З.И", "И.А", "К.И", "И.К", "К.Л"
};

char* journals[] = {
    "ZOV", "Физика", "Математика", "Информатика",
    "Программирование", "Кибернетика", "Робототехника"
};

#define size(arr) (sizeof(arr) / sizeof((arr)[0]))

/**
 * @brief Инициализация генератора, чтобы значения были разные
 * 
 */

void init_random() {
    srand((u_int)time(NULL));
}

void generate(Publication* pub) {
    if (!pub) return;

    char* t = titles[rand() % size(titles)];
    char* s = surnames[rand() % size(surnames)];
    char* i = initials[rand() % size(initials)];
    char* j = journals[rand() % size(journals)];

    snprintf(pub->title, sizeof(pub->title), "%s", t);
    snprintf(pub->author_surname, sizeof(pub->author_surname), "%s", s);
    snprintf(pub->author_initials, sizeof(pub->author_initials), "%s", i);
    snprintf(pub->journal, sizeof(pub->journal), "%s", j);

    pub->year = 2000 + (rand() % 25);
    pub->volume = 1 + (rand() % 20);
    pub->in_rinc = (rand() % 2 == 0);
    pub->pages = 5 + (rand() % 101);
    pub->citations = rand() % 500;
}