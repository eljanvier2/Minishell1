/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** task 03
*/

#include <unistd.h>
#include "my.h"

int mystrl(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return (i);
}

int my_strlen_spec(char *str, char delim)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == delim)
            i = checker(str, i, delim);
        j++;
        i = checker2(str, i, delim);
    }
    return j;
}

int my_strstrlen(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        i++;
    }
    return i;
}

int my_envlen(char *name)
{
    int i = 0;
    int size = 0;

    if (!name)
        return 0;
    while (name[i] != '=')
        i++;
    while (name[i] != '\0') {
        size++;
        i++;
    }
    return size;
}
