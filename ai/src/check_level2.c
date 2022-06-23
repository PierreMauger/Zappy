/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

bool check_level_3(client_t *client)
{
    inventory_t *inv = client->player->inv;

    if (inv->linemate < 2 || inv->sibur < 1 || inv->phiras < 2)
        return false;
    return true;
}

bool check_level_4(client_t *client)
{
    inventory_t *inv = client->player->inv;

    if (inv->linemate < 1 || inv->sibur < 2 || inv->phiras < 1
        || inv->deraumere < 1)
        return false;
    return true;
}

bool check_level_5(client_t *client)
{
    inventory_t *inv = client->player->inv;

    if (inv->linemate < 1 || inv->sibur < 1 || inv->mendiane < 3
        || inv->deraumere < 2)
        return false;
    return true;
}

bool check_level_6(client_t *client)
{
    inventory_t *inv = client->player->inv;

    if (inv->linemate < 1 || inv->deraumere < 2 || inv->sibur < 3
        || inv->phiras < 1)
        return false;
    return true;
}

bool check_level_7(client_t *client)
{
    inventory_t *inv = client->player->inv;

    if (inv->linemate < 2 || inv->deraumere < 2 || inv->sibur < 2
        || inv->mendiane < 2 || inv->phiras < 2 || inv->thystame < 1)
        return false;
    return true;
}
