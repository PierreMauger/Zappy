/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static int get_pos(client_t *client, pos_t *pos, char *word)
{
    word = strtok(NULL, " \t\n");
    if (word == NULL)
        return 1;
    pos->x = atoi(word);
    word = strtok(NULL, " \t\n");
    if (word == NULL)
        return 1;
    pos->y = (client->size_map.x - 1) - atoi(word);
    if (pos->x < 0 || pos->y < 0)
        return 1;
    return 0;
}

static int command(client_t *client, char *str)
{
    char *word = strtok(str, " \t\n");
    pos_t pos = {0};

    if (!word || get_pos(client, &pos, word) != 0)
        return 1;
    client->map[pos.y][pos.x].incantation = false;
    return 0;
}

int pie(client_t *client, char *str)
{
    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    return command(client, str);
}
