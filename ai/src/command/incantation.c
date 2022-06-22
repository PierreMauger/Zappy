/*
** EPITECH PROJECT, 2022
** incantation.c
** File description:
** incantation ai
*/

#include "zappy_ai.h"

int incantation(client_t *client, char *str)
{
    if (strcmp(str, "ok") == 0) {
        printf("%s[COMMAND]%s Incantation done\n", B, W);
        client->player->level++;
        return 0;
    }
    return 1;
}
