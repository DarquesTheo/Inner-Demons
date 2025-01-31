/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** compare deux chaines de caracteres
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (n > 0) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] == 0 || s2[i] == 0)
            return (s1[i] - s2[i]);
        n--;
        i++;
    }
    return (0);
}
