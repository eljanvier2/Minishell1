/*
** EPITECH PROJECT, 2022
** prompt
** File description:
** minishell prompt
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

void prompt(void)
{
    char cwd[FILENAME_MAX];
    int i = 0;

    my_putstr("\033[0;32m");
    my_putstr("\033[1m");
    my_putstr("→  ");
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        my_putstr("\033[0;36m");
        my_putstr("\033[1m");
        my_putstr(cwd);
    }
    my_putstr("\033[0;33m");
    my_putstr("\033[1m");
    my_putstr(" ✗ ");
    my_putstr("\033[0;37m");
}
