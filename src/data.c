#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"

/**
 * @brief Функция считывающая формат csv
 * 
 * @param file 
 * @param pub 
 * @return int 
 */

int read_publication_csv(FILE *file, Publication *pub){

    char str[1024];

    if(fgets(str,sizeof(str), file) == NULL){
        return 0;
    }

    str[strcspn(str, "\n")] = '\0';

    char *token = strtok(str, ",");
    if(!token) return 0;
    snprintf(pub->title, sizeof(pub->title), "%s", token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    snprintf(pub->author_surname, sizeof(pub->author_surname), "%s", token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    snprintf(pub->author_initials, sizeof(pub->author_initials), "%s", token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    snprintf(pub->journal, sizeof(pub->journal), "%s", token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    pub->year = atoi(token);

    token = strtok(NULL, ",");
    if(!token) return 0;
    pub->volume = atoi(token);

    token = strtok(NULL, ",");
    if (!token) return 0;
    pub->in_rinc = (strcmp(token, "true") == 0);

    token = strtok(NULL, ",");
    if (!token) return 0;
    pub->pages = atoi(token);

    token = strtok(NULL, ",");
    if (!token) return 0;
    pub->citations = atoi(token);

    return 1;

}