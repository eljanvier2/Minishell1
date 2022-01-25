/*
** EPITECH PROJECT, 2022
** str handling
** File description:
** various string operations
*/

#include <stdlib.h>
#include "my.h"

char *line_eraser(char *str)
{
    int i = 0;
    char *tmp = NULL;

    tmp = malloc(sizeof(char) * mystrl(str));
    if (my_strcmp(str, "\n") == 0)
        return NULL;
    while (str[i] != '\n') {
        tmp[i] = str[i];
        i++;
        }
    tmp[i] = '\0';
    return tmp;
}
