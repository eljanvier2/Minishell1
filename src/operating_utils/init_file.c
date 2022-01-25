/*
** EPITECH PROJECT, 2022
** init file
** File description:
** file for various variable initializers
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "structures.h"

input_t *init(input_t *elem, char **env)
{
    input_t *input_elem = malloc(sizeof(input_t));
    input_elem->env = env;
    input_elem->size = 10;
    input_elem->str = malloc(sizeof(char) * input_elem->size);
    input_elem->input = NULL;
    input_elem->chars = 0;
    input_elem->input_argc = 0;
    return input_elem;
}

input_t *reset(input_t *elem)
{
    elem->str = NULL;
    elem->input = NULL;
    elem->chars = '\0';
    elem->input_argc = 0;
    return elem;
}

char **returner_init(char **returner, char *str)
{
    returner = malloc(sizeof(char*) * (my_strlen_spec(str, ' ') + 1));
    for (int i = 0; i < my_strlen_spec(str, ' '); i++)
        returner[i] = malloc(sizeof(char) * (word_lenght(str, i, 0, ' ') + 1));
    return returner;
}

char **path_returner_init(char **returner, char *str)
{
    returner = malloc(sizeof(char*) * (my_strlen_spec(str, ':') + 1));
    for (int i = 0; i < my_strlen_spec(str, ':'); i++)
        returner[i] = malloc(sizeof(char) * (word_lenght(str, i, 0, ':') + 1));
    return returner;
}
