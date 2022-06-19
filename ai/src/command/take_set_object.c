/*
** EPITECH PROJECT, 2022
** take_set_object.c
** File description:
** take_set_object ai
*/

#include "zappy_ai.h"

static int split_take_object(client_t *client, char *str, size_t x, size_t y)
{
    if (strcmp(str, "linemate\n") == 0) {
        client->map[y][x].inv->linemate--;
        client->player->inv->linemate++;
    }
    if (strcmp(str, "mendiane\n") == 0) {
        client->map[y][x].inv->mendiane--;
        client->player->inv->mendiane++;
    }
    if (strcmp(str, "sibur\n") == 0) {
        client->map[y][x].inv->sibur--;
        client->player->inv->sibur++;
    }
    if (strcmp(str, "thystame\n") == 0) {
        client->map[y][x].inv->thystame--;
        client->player->inv->thystame++;
    }
    return 0;
}

int take_object(client_t *client, char *str)
{
    size_t y = client->player->pos.y;
    size_t x = client->player->pos.x;

    if (strcmp(str, "ko") == 0) {
        printf("%s[INFO]%s This object isn't in this case\n", M, W);
        return 1;
    }
    if (strcmp(str, "food\n") == 0) {
        client->map[y][x].inv->food--;
        client->player->inv->food++;
    }
    if (strcmp(str, "phiras\n") == 0) {
        client->map[y][x].inv->phiras--;
        client->player->inv->phiras++;
    }
    if (strcmp(str, "deraumere\n") == 0) {
        client->map[y][x].inv->deraumere--;
        client->player->inv->deraumere++;
    }
    return (split_take_object(client, str, x, y));
}

static int split_set_object(client_t *client, char *str, size_t x, size_t y)
{
    if (strcmp(str, "linemate") == 0) {
        client->map[y][x].inv->linemate++;
        client->player->inv->linemate--;
    }
    if (strcmp(str, "mendiane") == 0) {
        client->map[y][x].inv->mendiane++;
        client->player->inv->mendiane--;
    }
    if (strcmp(str, "sibur") == 0) {
        client->map[y][x].inv->sibur++;
        client->player->inv->sibur--;
    }
    if (strcmp(str, "thystame") == 0) {
        client->map[y][x].inv->thystame++;
        client->player->inv->thystame--;
    }
    return 0;
}

int set_object(client_t *client, char *str)
{
    size_t y = client->player->pos.y;
    size_t x = client->player->pos.x;

    if (strcmp(str, "ko") == 0) {
        printf("%s[INFO]%s Player don't have this object\n", M, W);
        return 1;
    }
    if (strcmp(str, "food") == 0) {
        client->map[y][x].inv->food++;
        client->player->inv->food--;
    }
    if (strcmp(str, "phiras") == 0) {
        client->map[y][x].inv->phiras++;
        client->player->inv->phiras--;
    }
    if (strcmp(str, "deraumere") == 0) {
        client->map[y][x].inv->deraumere++;
        client->player->inv->deraumere--;
    }
    return (split_set_object(client, str, x, y));
}
