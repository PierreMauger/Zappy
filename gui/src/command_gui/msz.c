/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static bool create_map(client_t *client)
{
    int h = 0;
    client->map = malloc(sizeof(map_t *) * (client->size_map.y + 1));

    if (!client->map)
        return false;
    for (h = 0; h != client->size_map.y; h++) {
        client->map[h] = malloc(sizeof(map_t) * (client->size_map.x + 1));
        if (!client->map[h])
            return false;
    }
    client->map[h] = NULL;
    return true;
}

int msz(client_t *client, char *str)
{
    if (!str) {
        fprintf(stderr, "%s[ERROR]%s bad arg", R, W);
        return 1;
    }
    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    client->size_map.x = atoi(str);
    client->size_map.y = atoi(strchr(str, ' '));
    if (!create_map(client)) {
        fprintf(stderr, "%s[ERROR]%s can't create map (malloc error)", R, W);
        return 1;
    }
    printf("x = %d y = %d\n", client->size_map.x, client->size_map.y);
    return 0;
}
