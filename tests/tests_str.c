/*
** EPITECH PROJECT, 2022
** tests criterion
** File description:
** tests criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void);

Test(my_putsterr, err_print1, .init = redirect_all_std)
{
    my_putsterr("problem");
    cr_assert_stderr_eq_str("problem");
}

Test(my_put_nbr, nbr_print1, .init = redirect_all_std)
{
    my_put_nbr(10);
    cr_assert_stdout_eq_str("10");
}

Test(my_put_nbr, nbr_print2, .init = redirect_all_std)
{
    my_put_nbr(-10);
    cr_assert_stdout_eq_str("-10");
}

Test(line_eraser, line_eraser_test1, .init = redirect_all_std)
{
    char *str = "bonjour\n";
    str = line_eraser(str);
    my_putstr(str);
    cr_assert_stdout_eq_str("bonjour");
}

Test(my_strcat, cat_test1, .init = redirect_all_std)
{
    char *str = "bonjour";
    char *str2 = "bonjour";

    my_putstr(my_strcat(str, str2));
    cr_assert_stdout_eq_str("bonjourbonjour");
}

Test(my_strncat, cat_test2, .init = redirect_all_std)
{
    char *str = "bonjour";
    char *str2 = "bonjour";

    my_putstr(my_strncat(str, str2, 3));
    cr_assert_stdout_eq_str("bonjourbon");
}

Test(my_strcmp, cmp_test1, .init = redirect_all_std)
{
    char *str = "bonjour";
    char *str2 = "bonjour";

    my_put_nbr(my_strcmp(str, str2));
    cr_assert_stdout_eq_str("0");
}

Test(my_strcmp, cmp_test2, .init = redirect_all_std)
{
    char *str = "bonjour";
    char *str2 = "bon";

    my_put_nbr(my_strcmp(str, str2));
    cr_assert_stdout_eq_str("1");
}

Test(my_strcmp, cmp_test3, .init = redirect_all_std)
{
    char *str = "bon";
    char *str2 = "bonjour";

    my_put_nbr(my_strcmp(str, str2));
    cr_assert_stdout_eq_str("-1");
}

Test(my_strcmp, cmp_test4, .init = redirect_all_std)
{
    char *str = NULL;
    char *str2 = NULL;

    my_put_nbr(my_strcmp(str, str2));
    cr_assert_stdout_eq_str("1");
}

Test(my_strcmp, cmp_test5, .init = redirect_all_std)
{
    char *str = "12345";
    char *str2 = "54321";

    my_put_nbr(my_strcmp(str, str2));
    cr_assert_stdout_eq_str("-1");
}

Test(my_strcmp, cmp_test6, .init = redirect_all_std)
{
    char *str2 = "12345";
    char *str = "54321";

    my_put_nbr(my_strcmp(str, str2));
    cr_assert_stdout_eq_str("1");
}

Test(my_strncmp, ncmp_test1, .init = redirect_all_std)
{
    char *str2 = "12345";
    char *str = "54321";

    my_put_nbr(my_strncmp(str, str2, 3));
    cr_assert_stdout_eq_str("1");
}

Test(my_strncmp, ncmp_test2, .init = redirect_all_std)
{
    char *str1 = "12345";
    char *str2 = "54321";

    my_put_nbr(my_strncmp(str1, str2, 3));
    cr_assert_stdout_eq_str("-1");
}

Test(my_strncmp, ncmp_test3, .init = redirect_all_std)
{
    char *str2 = "12345";
    char *str = "12345";

    my_put_nbr(my_strncmp(str, str2, 3));
    cr_assert_stdout_eq_str("0");
}