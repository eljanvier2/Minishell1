/*
** EPITECH PROJECT, 2022
** my execve
** File description:
** my execve
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

int my_execve(input_t *elem, char *path)
{
    int child_status = 0;
    pid_t pid = fork();

    if (pid == 0) {
        if (execve(path, elem->input, elem->env) == -1) {
            exit(-1);
        }
        exit(0);
    } else {
        waitpid(pid, &child_status, 0);
        return WEXITSTATUS(child_status);
    }
}

int bin_execve(input_t *elem)
{
    char *path = path_finder(elem->env);
    char **cleanpath = my_strtoword(path, ':', 1);

    for (int i = 0; cleanpath[i]; i++) {
        cleanpath[i] = path_strcat(cleanpath[i], elem->input[0], elem->input);
        if (my_execve(elem, cleanpath[i]) == 0)
            return 0;
    }
    return -1;
}
