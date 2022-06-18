/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

void print_inventory(inventory_t *inv)
{
    printf("food = %ld linemate = %ld deraumere = %ld sibur = %ld mendiane"
        " = %ld phiras = %ld thystame = %ld\n", inv->food, inv->linemate,
        inv->deraumere, inv->sibur, inv->mendiane, inv->phiras, inv->thystame);
}

void print_inventory_map(client_t *client)
{
    for (int y = 0; y != client->size_map.y; y++) {
        for (int x = 0; x != client->size_map.x; x++) {
            printf("y = %d x = %d : ", y, x);
            print_inventory(client->map[y][x].inv);
        }
    }
}
