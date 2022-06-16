/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils gui
*/

#include "zappy_gui.h"

void print_inventory(inventory_t *inv)
{
    printf("food = %ld\nlinemate = %ld\nderaumere = %ld\nsibur = %ld\nmendiane "
        "= %ld\nphiras = %ld\nthystame = %ld\n", inv->food, inv->linemate,
        inv->deraumere, inv->sibur, inv->mendiane, inv->phiras, inv->thystame);
}

void print_player(player_t *player)
{
    printf("dir = [%d] level = [%d] pos x = [%d] pos y = [%d] "
        "team_name = [%s] uuid = [%s]\n",
        player->dir, player->level, player->pos.x, player->pos.y,
        player->team_name, player->uuid);
    print_inventory(player->inv);
}
