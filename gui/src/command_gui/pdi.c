/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

int pdi(client_t *client, char *str)
{
    node_t *nd = NULL;
    node_t *save = NULL;
    char *uuid = get_one_word(str);
    player_t *head = ((player_t *)client->player->head->data);

    !uuid ? (uuid = strdup("0")) : 0;
    foreach_safe(client->map[head->pos.y][head->pos.x].player->head, nd, save)
        if (strcmp(((player_t *)nd->data)->uuid, uuid) == 0) {
            list_remove_node(client->map[head->pos.y][head->pos.x].player, nd);
            list_destroy_node(nd, NULL);
            break;
        }
    foreach_safe(client->player->head, nd, save)
        if (strcmp(((player_t *)nd->data)->uuid, uuid) == 0) {
            list_remove_node(client->player, nd);
            list_destroy_node(nd, free_player);
            break;
        }
    free(uuid);
    return 0;
}
