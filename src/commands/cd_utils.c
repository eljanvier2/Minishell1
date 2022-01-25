/*
** EPITECH PROJECT, 2022
** cd utils
** File description:
** various cd functions
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

void cd_hyphen(input_t *elem)
{
    char *tmp = my_oldpwd(elem);
    char cwd[FILENAME_MAX];

    my_setenv("OLDPWD", my_pwd(elem), elem);
    my_putstr(tmp);
    my_putchar('\n');
    chdir(tmp);
    my_setenv("PWD", getcwd(cwd, sizeof(cwd)), elem);
}

void home_cd(input_t *elem)
{
    char cwd[FILENAME_MAX];

    my_setenv("OLDPWD", my_pwd(elem), elem);
    chdir(my_home(elem));
    my_setenv("PWD", getcwd(cwd, sizeof(cwd)), elem);
}

void my_cd(input_t *elem)
{
    char cwd[FILENAME_MAX];

    if (my_strcmp(elem->input[1], "-") == 0) {
        cd_hyphen(elem);
        return;
    }
    if (my_strcmp(elem->input[1], "~") == 0 || elem->input[1] == NULL) {
        home_cd(elem);
        return;
    }
    my_setenv("OLDPWD", my_pwd(elem), elem);
    if (chdir(elem->input[1]) != 0) {
        my_putsterr(elem->input[1]);
        my_putsterr(": No such file or directory.");
        my_putsterr("\n");
        return;
    }
    my_setenv("PWD", getcwd(cwd, sizeof(cwd)), elem);
}
