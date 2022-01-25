/*
** EPITECH PROJECT, 2022
** headers
** File description:
** headers for minishell 1
*/

#include "structures.h"

#ifndef MY_H_
    #define MY_H_

    #define ls "/usr/bin/ls"

void run(input_t *elem);
void my_putchar(char c);
void prompt(void);
void env_print(input_t *elem);
void cd_hyphen(input_t *elem);
void my_cd(input_t *elem);
void to_the_top(char *str, input_t *elem, int i);
int my_setenv(const char *name, const char *val, input_t *elem);
int my_unsetenv(const char *name, input_t *elem);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int mystrl(char const *str);
int my_strlen2(char const *str);
int my_strstrlen(char **str);
int my_envlen(char *name);
int my_strlen_spec(char *str, char delim);
int my_putsterr(char const *str);
int my_put_nbr(int nb);
int word_lenght(char *str, int i, int shouldReset, char delim);
int bin_execve(input_t *elem);
int my_execve(input_t *elem, char *path);
int checker(char *str, int i, char delim);
int checker2(char *str, int i, char delim);
int arg_cont(char **input, int input_argc);
char **my_strtoword(char *str, char delim, int path_switch);
char **returner_init(char **returner, char *str);
char **path_returner_init(char **returner, char *str);
char *line_eraser(char *str);
char *my_strncat(char *dest , char const *src, int n);
char *my_strcat(char *dest , char const *src);
char *path_strcat(char *dest , char const *src, char **input);
char *env_cat(const char *name, const char *value, int size);
char *my_oldpwd(input_t *elem);
char *my_pwd(input_t *elem);
char *my_home(input_t *elem);
char *path_finder(char **env);
input_t *init(input_t *elem, char **env);
input_t *reset(input_t *elem);

#endif
