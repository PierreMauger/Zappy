/*
** EPITECH PROJECT, 2022
** movement.c
** File description:
** movement ai
*/

#include "zappy_ai.h"

int forward_movement(char *str)
{
    if (strcmp(str, "ok\n") == 0) {
        printf("%s[COMMAND]%s Forward\n", G, W);
        return 0;
    }
    return 1;
}

int right_movement(char *str)
{
    if (strcmp(str, "ok\n") == 0) {
        printf("%s[COMMAND]%s Right\n", G, W);
        return 0;
    }
    return 1;
}

int left_movement(char *str)
{
    if (strcmp(str, "ok\n") == 0) {
        printf("%s[COMMAND]%s Left\n", G, W);
        return 0;
    }
    return 1;
}
