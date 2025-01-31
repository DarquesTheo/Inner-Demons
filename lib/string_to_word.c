/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** task 04
*/

#include <stdlib.h>

int intoralpha(char const c)
{
    if (c > 32)
        return 1;
    return 0;
}

int nb_words(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (intoralpha(str[i]) == 1 && intoralpha(str[i + 1]) == 0){
            nb++;
        }
    }
    return nb;
}

char **def_size(char const *str)
{
    char **new;
    int tmp = 1;
    int j = 0;

    new = (char **)malloc(sizeof(char *) * (nb_words(str) + 1));
    for (int i = 0; str[i] != '\0'; i++){
        if (intoralpha(str[i])){
            tmp++;
        }
        if (intoralpha(str[i]) == 1 && intoralpha(str[i + 1]) == 0){
            new[j] = (char *)malloc(sizeof(char) * tmp);
            tmp = 1;
            j++;
        }
    }
    return new;
}

char **string_to_word(char const *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **new;

    new = def_size(str);
    for (i = 0; str[i] != '\0'; i++){
        if (intoralpha(str[i]) == 1){
            new[j][k] = str[i];
            k++;
        }
        if (intoralpha(str[i]) == 1 && intoralpha(str[i + 1]) == 0){
            new[j][k] = '\0';
            j++;
            k = 0;
        }
    }
    new[j] = NULL;
    return new;
}
