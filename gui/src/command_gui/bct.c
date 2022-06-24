/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static char *fill_inventory(client_t *client, char *str)
{
    size_t x = atoi(str);
    char *save = go_next_space(str);
    size_t y = (client->size_map.x - 1) - atoi(save);

    save = go_next_space(save);
    client->map[y][x].inv->food = atoi(save);
    save = go_next_space(save);
    client->map[y][x].inv->linemate = atoi(save);
    save = go_next_space(save);
    client->map[y][x].inv->deraumere = atoi(save);
    save = go_next_space(save);
    client->map[y][x].inv->sibur = atoi(save);
    save = go_next_space(save);
    client->map[y][x].inv->mendiane = atoi(save);
    save = go_next_space(save);
    client->map[y][x].inv->phiras = atoi(save);
    save = go_next_space(save);
    client->map[y][x].inv->thystame = atoi(save);
    save = go_next_space(save);
    return save;
}

int bct(client_t *client, char *str)
{
    char *save = str;

    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    do {
        save = fill_inventory(client, save);
    } while (save);
    return 0;
}
