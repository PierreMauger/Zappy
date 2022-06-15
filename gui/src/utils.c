/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils gui
*/

#include "zappy_gui.h"

char *move_str(char *str)
{
    size_t i = 0;

    while (str[i] == ' ')
        i++;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
        i++;
    return &str[i];
}

char *get_one_word(char *str)
{
    char *word = NULL;
    size_t i = 0;
    size_t n = 0;
    size_t len = 0;
    size_t s = 0;

    if (!str)
        return NULL;
    for (; str[i] == ' '; i++);
    for (n = i; str[n] != '\0' && str[n] != ' ' && str[n] != '\n'; n++, len++);
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    for (; str[i] != '\0' && str[i] != ' ' && str[n] != '\n'; i++, s++)
        word[s] = str[i];
    word[s] = '\0';
    return word;
}