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

void to_the_top(char *str, input_t *elem, int i)
{
    char *tmp = NULL;

    while (my_strcmp(elem->env[0], str) != 0) {
        tmp = malloc(sizeof(char) * mystrl(elem->env[i - 1]));
        tmp = elem->env[i - 1];
        elem->env[i - 1] = str;
        elem->env[i] = tmp;
        tmp = NULL;
        i--;
    }
}
