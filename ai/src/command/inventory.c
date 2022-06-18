/*
** EPITECH PROJECT, 2022
** inventory.c
** File description:
** inventory ai
*/

#include "zappy_ai.h"

void fill_inventory_player(player_t *player, char *content)
{
    for (char *stone; (stone = get_cell(content)); free(stone)) {
        if (strstr(stone, "food") != NULL)
            player->inv->food = my_getnbr(stone);
        if (strstr(stone, "deraumere") != NULL)
            player->inv->deraumere = my_getnbr(stone);
        if (strstr(stone, "linemate") != NULL)
            player->inv->linemate = my_getnbr(stone);
        if (strstr(stone, "mendiane") != NULL)
            player->inv->mendiane = my_getnbr(stone);
        if (strstr(stone, "phiras") != NULL)
            player->inv->phiras = my_getnbr(stone);
        if (strstr(stone, "sibur") != NULL)
            player->inv->sibur = my_getnbr(stone);
        if (strstr(stone, "thystame") != NULL)
            player->inv->thystame = my_getnbr(stone);
        if ((content = go_next_chr(content, ',')))
            (char *)((size_t)content++);
    }
}

int inventory(client_t *client, char *str)
{
    char *save = str;

    fill_inventory_player(client->player, save);
    print_inventory(client->player->inv);
    return 0;
}
