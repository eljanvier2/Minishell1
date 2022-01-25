/*
** EPITECH PROJECT, 2022
** env ops
** File description:
** functions used for env operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "structures.h"
#include <limits.h>

void env_print(input_t *elem)
{
    for (int i = 0; elem->env[i] != NULL; i++) {
        my_putstr(elem->env[i]);
        my_putchar('\n');
    }
}

int my_unsetenv(const char *name, input_t *elem)
{
    int i = 0;

    if (!name) {
        my_putsterr("unsetenv: Too few arguments.\n");
        return 84;
    }
    while (elem->env[i] != NULL) {
        if (my_strncmp(elem->env[i], name, mystrl(name)) == 0) {
            to_the_top(elem->env[i], elem, i);
            elem->env++;
            return 0;
        }
        i++;
    }
    return 0;
}

int setenv_output(const char *name, input_t *elem)
{
    if (name == NULL) {
        env_print(elem);
        return 1;
    }
    if (elem->input_argc > 3) {
        my_putsterr("setenv: Too many arguments.\n");
        return 84;
    }
    return 0;
}

int my_setenv(const char *name, const char *val, input_t *elem)
{
    int i = 0;
    int size = mystrl(name);
    int env_size = my_strstrlen(elem->env);
    int read_return = 0;

    if ((read_return = setenv_output(name, elem)) != 0)
        return read_return;
    while (elem->env[i] != NULL) {
        if (my_strncmp(elem->env[i], name, size) == 0) {
            elem->env[i] = env_cat(name, val, (mystrl(name) + mystrl(val)));
            return 0;
        }
        i++;
    }
    elem->env[i] = env_cat(name, val, (mystrl(name) + mystrl(val)));
    if (i == env_size)
        elem->env[i + 1] = NULL;
    return 0;
}
