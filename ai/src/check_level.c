/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

bool check_level_1(client_t *client)
{
    if (client->player->inv->linemate < 1)
        return false;
    return true;
}

bool check_level_2(client_t *client)
{
    inventory_t *inv = client->player->inv;

    if (inv->linemate < 1 || inv->deraumere < 1 || inv->sibur < 1)
        return false;
    return true;
}
