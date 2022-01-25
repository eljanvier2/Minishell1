/*
** EPITECH PROJECT, 2022
** main file
** File description:
** main file
*/

#include "my.h"
#include "structures.h"

int main(int argc, char **argv, char **env)
{
    input_t *input_elem = init(input_elem, env);

    prompt();
    run(input_elem);
    return 0;
}
