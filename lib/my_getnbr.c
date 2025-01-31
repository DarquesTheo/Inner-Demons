/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** c'est atoi
*/

int nb_0(char const *str, int i)
{
    while (str[i] == '0') {
        i++;
    }
    return (i);
}

int test_max_int(int neg, long long int nb)
{
    int nb_final = 0;

    if (neg % 2 == 1) {
        nb = -nb;
    }
    if (nb > 2147483647 || nb < -2147483648) {
        return (nb_final);
    }
    nb_final = nb;
    return (nb_final);
}

long long int get_nb_provi(long long int p, int len_nb, char const *str, int i)
{
    long long int nb = 0;

    while (len_nb > 0) {
        nb = nb + (str[i + len_nb - 1] - 48) * p;
        p = p * 10;
        len_nb--;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    long long int puissance = 1;
    int neg = 0;
    int i = 0;
    long long int nb = 0;
    int nb_final;
    int len_nb = 0;

    i = nb_0(str, i);
    while (str[i + len_nb] >= '0' && str[i + len_nb] <= '9')
        len_nb++;
    if (len_nb > 15)
        return (0);
    nb = get_nb_provi(puissance, len_nb, str, i);
    nb_final = test_max_int(neg, nb);
    return (nb_final);
}
