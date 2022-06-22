/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

int pdi(client_t *client, char *str)
{
    node_t *node;
    node_t *save;
    char *uuid = get_one_word(str);

    if (!uuid)
        return 1;
    printf("uuid %s\n", uuid);
    exit(0);
    foreach_safe(client->player->head, node, save) {
        if (strcmp(((player_t *)node->data)->uuid, uuid) == 0) {
            list_destroy_node(node, free_player);
            break;
        }
    }
    return 0;
}
