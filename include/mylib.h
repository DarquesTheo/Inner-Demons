/*
** EPITECH PROJECT, 2023
** mylib.h
** File description:
** header for the my_printf project
*/

#ifndef MY_LIB_H
    #define MY_LIB_H

    #include <math.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <sys/types.h>
    #include <sys/stat.h>

int my_printf(const char *format, ...);

int flags_manager(char const *format, va_list list, int co_mod, char *flag);
int int_flags_manager(char *flag, long long int arg, char const *format,
    int co_mod);
int float_flags_manager(char *flag, double arg, char const *format,
    int co_mod);
int str_flags_manager(char *flag, char *arg);
int lint_flags_manager(char *flag, long int arg,
    char const *format, int co_mod);

int my_count_putchar(char c);
int my_count_putnbr(long long int nb);
int my_count_putstr(const char *str);
void my_putsterr(char *str);
int my_count_puthex(int nb, int is_upper);
int my_count_putfloat(double *nb, int accuracy);
int my_count_putsc(double *nb, int precision, int upper);
int my_count_putunsigned(unsigned int nb);
int my_display_octal(unsigned int nb);
int my_display_long_octal(unsigned long nb);
int my_count_putptr(void *ptr);
int my_strlen(char const *str);
int my_tablen(char **str);
int my_countnbr(long long int nb);
char *my_strcat(char *dest, char const *src);
char *concat(const char *s1, const char *s2);
char *my_sputnbr(long long int nb, char *str);
int is_number(char c);
int str_to_int(char *str);
void show_tab(char **tab);

unsigned long int calc_power_pos(int nb, int p);

int indicator_manager(char const *format, char flag, int *i, va_list list);
int indicator_int(char const *format, int i);
int zero_indicator(char format, int len);
int minus_indicator(char const *format, int co_mod, int len);
int hashtag_indicator_int(char *flag, char const *format,
    int co_mod, long long int arg);

char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array(char const *str);
char **string_to_word(char const *str);

char get_flag(char c);
int is_flag(char c);
int is_size_prefix(char c);

char *my_memset(char *str, char c, int nb);
int my_printf(const char *format, ...);
void my_putstr(char *str);

int my_strncmp(char const *s1, char const *s2, int n);
int my_getnbr(char const *str);

#endif
