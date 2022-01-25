/*
** EPITECH PROJECT, 2022
** step 4
** File description:
** displaying the prompt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <linux/limits.h>
#include "structures.h"
#include "my.h"

void non_builtin(input_t *elem)
{
    if (elem->str != NULL && my_execve(elem, elem->input[0]) != 0)
        if (bin_execve(elem) != 0) {
            my_putsterr(elem->input[0]);
            my_putsterr(": Command not found.");
            my_putsterr("\n");
        }
}

int arg_cont(char **input, int input_argc)
{
    if (input)
        for (int i = 0; input[i] != NULL; i++)
            input_argc++;
    return input_argc;
}

void command_parse(input_t *elem)
{
    elem->input = my_strtoword(elem->str, ' ', 0);
    if (elem->str != NULL && my_strcmp(elem->input[0], "env") == 0) {
        env_print(elem);
        return;
    }
    if (elem->str != NULL && my_strcmp(elem->input[0], "cd") == 0) {
        my_cd(elem);
        return;
    }
    if (elem->str != NULL && my_strcmp(elem->input[0], "setenv") == 0) {
        if (arg_cont(elem->input, elem->input_argc) > 2)
            my_setenv(elem->input[1], elem->input[2], elem);
        else
            my_setenv(elem->input[1], NULL, elem);
        return;
    }
    if (elem->str != NULL && my_strcmp(elem->input[0], "unsetenv") == 0) {
        my_unsetenv(elem->input[1], elem);
        return;
    }
    non_builtin(elem);
}

void run(input_t *elem)
{
    while ((elem->chars = getline(&(elem->str), &elem->size, stdin)) != -1) {
        elem->str = line_eraser(elem->str);
        if (my_strcmp(elem->str, "exit") == 0)
            exit(0);
        command_parse(elem);
        prompt();
        elem = reset(elem);
    }
}
