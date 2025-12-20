#include "compare.h"
#include "stack.h"
typedef unsigned int u_int;

 int cmp_int(u_int p1, u_int p2) {
    return (p1 > p2) ? 1 : (p1 < p2) ? -1 : 0;
}

 int cmp_bool(bool p1, bool p2) {
    return (p1 > p2) ? 1 : (p1 < p2) ? -1 : 0;
}
/**
 * @brief Компараторо по возрастанию
 * 
 * @param p1 
 * @param p2 
 * @return int -1 0 1
 */

int compare_asc(const Publication* p1, const Publication* p2) {
    int cmp;

    cmp = strcmp(p1->title, p2->title);
    if (cmp) return cmp;

    cmp = strcmp(p1->author_surname, p2->author_surname);
    if (cmp) return cmp;

    cmp = strcmp(p1->author_initials, p2->author_initials);
    if (cmp) return cmp;

    cmp = strcmp(p1->journal, p2->journal);
    if (cmp) return cmp;

    cmp = cmp_int(p1->year, p2->year);
    if (cmp) return cmp;

    cmp = cmp_int(p1->volume, p2->volume);
    if (cmp) return cmp;

    cmp = cmp_bool(p1->in_rinc, p2->in_rinc);
    if (cmp) return cmp;

    cmp = cmp_int(p1->citations, p2->citations);
    if (cmp) return cmp;

    cmp = cmp_int(p1->pages, p2->pages);
    if (cmp) return cmp;

    return 0;
}

/**
 * @brief Компоратор по убыванию
 * 
 * @param p1 
 * @param p2 
 * @return int -1 0 1
 */

int compare_desc(const Publication* p1, const Publication* p2){
    return -compare_asc(p1, p2);
}