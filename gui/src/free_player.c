/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client gui
*/

#include "zappy_gui.h"

void free_player(void *data)
{
    player_t *player = data;

    if (player->uuid)
        free(player->uuid);
    free(player);
}
