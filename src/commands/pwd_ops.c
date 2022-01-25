/*
** EPITECH PROJECT, 2022
** pwd ops
** File description:
** various pwd operations
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
#include <linux/limits.h>

char *my_home(input_t *elem)
{
    char *home = malloc(sizeof(char) * PATH_MAX);
    int i = 0;
    int j = 0;

    while (my_strncmp(elem->env[i], "HOME", 4) != 0)
        i++;
    while (elem->env[i][j] != '=')
        j++;
    j++;
    for (int k = 0; elem->env[i][j] != '\0'; k++) {
        home[k] = elem->env[i][j];
        j++;
        home[k + 1] = '\0';
    }
    return home;
}

char *my_pwd(input_t *elem)
{
    char *pwd = malloc(sizeof(char) * PATH_MAX);
    int i = 0;
    int j = 0;

    while (my_strncmp(elem->env[i], "PWD", 3) != 0)
        i++;
    while (elem->env[i][j] != '=')
        j++;
    j++;
    for (int k = 0; elem->env[i][j] != '\0'; k++) {
        pwd[k] = elem->env[i][j];
        j++;
        pwd[k + 1] = '\0';
    }
    return pwd;
}

char *my_oldpwd(input_t *elem)
{
    char *old_pwd = malloc(sizeof(char) * PATH_MAX);
    int i = 0;
    int j = 0;

    while (my_strncmp(elem->env[i], "OLDPWD", 6) != 0)
        i++;
    while (elem->env[i][j] != '=')
        j++;
    j++;
    for (int k = 0; elem->env[i][j] != '\0'; k++) {
        old_pwd[k] = elem->env[i][j];
        j++;
        old_pwd[k + 1] = '\0';
    }
    return old_pwd;
}
