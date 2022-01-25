/*
** EPITECH PROJECT, 2022
** str to word
** File description:
** converts char to char
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int checker(char *str, int i, char delim)
{
    while (str[i] == delim)
        i++;
    return i;
}

int checker2(char *str, int i, char delim)
{
    while (str[i] != delim && str[i] != '\0')
        i++;
    return i;
}

int word_lenght(char *str, int i, int shouldReset, char delim)
{
    static int next = 0;
    static int previous = 0;
    i = next;
    previous = next;

    if (shouldReset) {
        next = 0;
        previous = 0;
        return 0;
    }
    while (str[i] != delim && str[i] != '\0') {
        i++;
        next++;
    }
    while (str[next] == delim && str[next] != '\0')
        next++;
    return (i - previous);
}

char **returner_parse(char **returner, char *str, int path_switch)
{
    if (path_switch == 0)
        returner = returner_init(returner, str);
    else
        returner = path_returner_init(returner, str);
    return returner;
}

char **my_strtoword(char *str, char delim, int path_switch)
{
    if (str == NULL)
        return NULL;
    char **returner = returner_parse(returner, str, path_switch);
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            i = checker(str, i, delim);
            returner[j][k] = '\0';
            j++;
            k = 0;
        }
        returner[j][k] = str[i];
        k++;
    }
    returner[j][k] = '\0';
    j++;
    returner[j] = NULL;
    word_lenght(str, j, 1, delim);
    return returner;
}
