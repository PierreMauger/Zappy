/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static command_tna_write_team_name(core_t *core, client_t *client,
    char *team_name)
{
    char *buff = NULL;

    if (asprintf(&buff, "tna %s\n", team_name) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        client_push_command(core->server, client, strdup("suc\n"));
    }
}

void command_tna(core_t *core, client_t *client, UNUSED char *command)
{
    node_t *node = NULL;
    team_t *team = NULL;

    foreach(node, core->game->teams->head) {
        team = (team_t *)node->data;
        command_tna_write_team_name(core, client, team->name);
    }
}
