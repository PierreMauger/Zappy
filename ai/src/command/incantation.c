/*
** EPITECH PROJECT, 2022
** incantation.c
** File description:
** incantation ai
*/

#include "zappy_ai.h"

int incantation(client_t *client, char *str)
{
    print_inventory(client->map[client->player->pos.y][client->player->pos.x].inv);
    if (strcmp(str, "Elevation underway") == 0) {
        printf("%s[COMMAND]%s Incantation start\n", B, W);
        exit(8);
        return 0;
    }
    else if (strlen(str) >= 14 && strncmp(str, "Current level:", 14) == 0) {
        printf("%s[COMMAND]%s Incantation done\n", G, W);
        client->player->level++;
        exit(8);
        return 0;
    }
    printf("%s[COMMAND]%s Incantation fail\n", R, W);
    exit(8);
    return 1;
}
