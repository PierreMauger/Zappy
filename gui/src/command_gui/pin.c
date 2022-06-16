/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static void fill_inv_player(node_t *node, char *save)
{
    save = go_next_space(save);
    save = go_next_space(save);
    save = go_next_space(save);
    ((player_t *)node->data)->inv->food = atoi(save);
    save = go_next_space(save);
    ((player_t *)node->data)->inv->linemate = atoi(save);
    save = go_next_space(save);
    ((player_t *)node->data)->inv->deraumere = atoi(save);
    save = go_next_space(save);
    ((player_t *)node->data)->inv->sibur = atoi(save);
    save = go_next_space(save);
    ((player_t *)node->data)->inv->mendiane = atoi(save);
    save = go_next_space(save);
    ((player_t *)node->data)->inv->phiras = atoi(save);
    save = go_next_space(save);
    ((player_t *)node->data)->inv->thystame = atoi(save);
    free(save);
}

int pin(client_t *client, char *str)
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
    fill_inv_player(node, save);
    return 0;
}
