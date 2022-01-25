/*
** EPITECH PROJECT, 2022
** path ops
** File description:
** path ops
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

char *path_rm(char *path_variable)
{
    int i = 0;
    while (path_variable[i] != '/')
        i++;
    path_variable += i;
    return path_variable;
}

char *path_finder(char **env)
{
    int i = 0;
    int path_size = 0;
    int active = 1;
    char *path = NULL;

    while (env[i] != NULL && active) {
        i++;
        if (my_strncmp(env[i], "PATH", 4) == 0) {
            path_size = mystrl(env[i]);
            active = 0;
        }
    }
    path = malloc(sizeof(char) * (path_size + 1));
    path = env[i];
    path[path_size] = '\0';
    path = path_rm(path);
    return path;
}

char *path_strcat(char *dest , char const *src, char **input)
{
    int i = 0;
    int n = 0;
    int size = mystrl(src) + mystrl(dest) + mystrl(input[0]);
    char *returned = malloc(sizeof(char) * (size + 1));

    while (dest[i] != '\0') {
        returned[i] = dest[i];
        i++;
    }
    returned[i] = '/';
    i++;
    while (src[n] != '\0') {
        returned[i] = src[n];
        n++;
        i++;
    }
    returned[i] = '\0';
    return returned;
}
