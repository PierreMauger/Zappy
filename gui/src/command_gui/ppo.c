/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static bool split_ppo(client_t *client, node_t *node, char *save, char *uuid)
{
    char *temp = NULL;

    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->pos.x = atoi(temp);
    free(temp);
    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->pos.y = (client->size_map.x - 1) - atoi(temp);
    free(temp);
    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->dir = atoi(temp);
    free(temp);
    free(uuid);
    return true;
}

int ppo(client_t *client, char *str)
{
    node_t *node = NULL;
    char *uuid = NULL;
    char *save = strdup(str);

    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    uuid = get_one_word(save);
    foreach (client->player->head, node) {
        if (strcmp(((player_t *)node->data)->uuid, uuid) == 0)
            break;
    }
    if (!split_ppo(client, node, save, uuid))
        fprintf(stderr, "%s[ERROR]%s can't malloc ppo", R, W);
    return 0;
}

static bool split_plv(node_t *node, char *save, char *uuid)
{
    char *temp = NULL;

    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->level = atoi(temp);
    free(temp);
    free(save);
    free(uuid);
    return true;
}

int plv(client_t *client, char *str)
{
    node_t *node = NULL;
    char *uuid = NULL;
    char *save = strdup(str);

    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    uuid = get_one_word(save);
    foreach(client->player->head, node) {
        if (strcmp(((player_t *)node->data)->uuid, uuid) == 0)
            break;
    }
    if (!split_plv(node, save, uuid))
        fprintf(stderr, "%s[ERROR]%s can't malloc plv", R, W);
    return 0;
}
