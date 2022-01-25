/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** tests criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(mystrl, lenght_test, .init = redirect_all_std)
{
    my_put_nbr(mystrl("bonJour"));
    cr_assert_stdout_eq_str("7");
}

Test(my_strlen2, lenght_test2, .init = redirect_all_std)
{
    my_put_nbr(my_strlen2("bonJour\nca va"));
    cr_assert_stdout_eq_str("7");
}

Test(my_envlen, lenght_test3, .init = redirect_all_std)
{
    my_put_nbr(my_envlen("PWD=BONJOUR"));
    cr_assert_stdout_eq_str("8");
}

Test(my_strtoword, strtoword_test1, .init = redirect_all_std)
{
    char *str = "bonjour comment va";
    char **str2 = my_strtoword(str, ' ', 0);

    for (int i = 0; str2[i] != NULL; i++) {
        my_putstr(str2[i]);
        my_putchar('\n');
    }
    cr_assert_stdout_eq_str("bonjour\ncomment\nva\n");
}

Test(arg_cont, cont_test1, .init = redirect_all_std)
{
    char **str = NULL;
    int cont = 0;

    my_put_nbr(arg_cont(str, cont));
    cr_assert_stdout_eq_str("0");
}

Test(arg_cont, cont_test2, .init = redirect_all_std)
{
    char **str = malloc(sizeof(char*) * 2);
    str[0] = "bonjour";
    str[1] = '\0';
    int cont = 0;

    my_put_nbr(arg_cont(str, cont));
    cr_assert_stdout_eq_str("1");
}