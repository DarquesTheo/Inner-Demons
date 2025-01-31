/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rm_char_from_str
*/

//remove all times c is in str
void rm_char_from_str(char *str, char c)
{
    int src_hint = 0;
    int dest_hint = 0;

    while (str[src_hint] != '\0') {
        if (str[src_hint] != c) {
            str[dest_hint] = str[src_hint];
            dest_hint++;
        }
        src_hint++;
    }
    str[dest_hint] = '\0';
}
