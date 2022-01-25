/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** task 07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (!s1 || !s2)
        return 1;
    while (s1[i] != '\0' && s2[i] != '\0' || i < n) {
        if (s1[i] == s2[i])
            i++;
        else if (s1[i] > s2[i])
            return (1);
        else
            return (-1);
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    else if (s2[i] == '0' && s1[i] != '\0')
        return (1);
    else
        return 0;
}
