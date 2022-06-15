/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static void fill_inventory(client_t *client, char *save, size_t x, size_t y)
{
    save = strchr(save, ' ');
    client->map[y][x].inv->food = atoi(save);
    save = strchr(save, ' ');
    client->map[y][x].inv->linemate = atoi(save);
    save = strchr(save, ' ');
    client->map[y][x].inv->deraumere = atoi(save);
    save = strchr(save, ' ');
    client->map[y][x].inv->sibur = atoi(save);
    save = strchr(save, ' ');
    client->map[y][x].inv->mendiane = atoi(save);
    save = strchr(save, ' ');
    client->map[y][x].inv->phiras = atoi(save);
    save = strchr(save, ' ');
    client->map[y][x].inv->thystame = atoi(save);
}

int bct(client_t *client, char *str)
{
    size_t x = atoi(str);
    char *save = strchr(str, ' ');
    size_t y = atoi(save);


    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    fill_inventory(client, save, x, y);
    return 0;
}
