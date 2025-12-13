#include "compare.h"

int compare_publications(const Publication* p1, const Publication* p2) {
    int cmp;

    cmp = strcmp(p1->title, p2->title);
    if (cmp != 0) return cmp;

    cmp = strcmp(p1->author_surname, p2->author_surname);
    if (cmp != 0) return cmp;

    cmp = strcmp(p1->author_initials, p2->author_initials);
    if (cmp != 0) return cmp;

    cmp = strcmp(p1->journal, p2->journal);
    if (cmp != 0) return cmp;

    if (p1->year != p2->year)
        return (p1->year > p2->year) ? 1 : -1;

    if (p1->volume != p2->volume)
        return (p1->volume > p2->volume) ? 1 : -1;

    if (p1->in_rinc != p2->in_rinc)
        return (p1->in_rinc > p2->in_rinc) ? 1 : -1;

    if (p1->citations != p2->citations)
        return (p1->citations > p2->citations) ? 1 : -1;

    if (p1->pages != p2->pages)
        return (p1->pages > p2->pages) ? 1 : -1;

    return 0;
}