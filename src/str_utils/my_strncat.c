/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** task 03
*/

#include <stdlib.h>

char *my_strncat(char *dest , char const *src, int n)
{
    int i = 0;
    int j = 0;
    char *returned = malloc(sizeof(dest) + sizeof(src));

    while (dest[i] != '\0') {
        returned[i] = dest[i];
        i++;
    }
    while (src[j] != '\0' && j < n) {
        returned[i] = src[j];
        i++;
        j++;
    }
    returned[i] = '\0';
    return returned;
}

char *my_strcat(char *dest , char const *src)
{
    int i = 0;
    int n = 0;
    char *returned = malloc(sizeof(dest) + sizeof(src));

    while (dest[i] != '\0') {
        returned[i] = dest[i];
        i++;
    }
    while (src[n] != '\0') {
        returned[i] = src[n];
        n++;
        i++;
    }
    returned[i] = '\0';
    return returned;
}

char *env_cat(const char *name, const char *value, int size)
{
    char *returned_val = NULL;
    int i = 0;

    if (!(returned_val = malloc(sizeof(char) * (size + 2))))
        return NULL;
    for (i = 0; name[i] != '\0'; i++)
        returned_val[i] = name[i];
    returned_val[i] = '=';
    i++;
    if (value != NULL) {
        for (int j = 0; value[j] != '\0'; j++) {
            returned_val[i] = value[j];
            i++;
        }
    }
    returned_val[i] = '\0';
    return returned_val;
}
