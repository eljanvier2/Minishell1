/*
** EPITECH PROJECT, 2022
** structures
** File description:
** structures used for minishell1 project
*/

#include <stdio.h>

#ifndef MYSTRUCT_H_
    #define MYSTRUCT_H_

typedef struct manage_input {
    char *str;
    size_t size;
    size_t chars;
    char **input;
    char **env;
    int input_argc;
} input_t;

#endif
