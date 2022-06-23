/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *get_level_str(size_t new_lvl)
{
    char *buff = NULL;

    if (asprintf(&buff, "Current level: %ld\n", new_lvl) == -1)
        return NULL;
    return buff;
}

static void game_increase_trantorians_level(core_t *core,
    incantation_t *incantation)
{
    node_t *node = NULL;
    trantorian_t *trant = NULL;
    char *temp = NULL;

    foreach(incantation->trantorians->head, node) {
        trant = (trantorian_t *)node->data;
        trant->level++;
        temp = get_level_str(trant->level);
        if (temp == NULL) {
            fprintf(stderr, "[ERROR] Malloc failed\n");
            continue;
        }
        client_push_command(core->server, trant->client, temp);
    }
}

static bool game_update_invocation(core_t *core, incantation_t *incantation)
{
    if (incantation->it_rem > 0) {
        incantation->it_rem--;
        return false;
    }
    game_increase_trantorians_level(core, incantation);
    return true;
}

void game_update_invocations(core_t *core)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    incantation_t *incantation = NULL;

    foreach_safe(core->game->incantations->head, node, safe) {
        incantation = (incantation_t *)node->data;
        if (game_update_invocation(core, incantation) == true) {
            list_remove_node(core->game->incantations, node);
            list_destroy_node(node, (void (*)(void *))incantation_destroy);
        }
    }
}
