/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static void command_tna_write_team_name(core_t *core, client_t *client,
    char *team_name)
{
    char *buff = NULL;

    if (asprintf(&buff, "tna %s\n", team_name) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return;
    }
    client_push_command(core->server, client, buff);
}

void command_tna(core_t *core, client_t *client, UNUSED char *command)
{
    node_t *node = NULL;
    team_t *team = NULL;

    foreach(core->game->teams->head, node) {
        team = (team_t *)node->data;
        command_tna_write_team_name(core, client, team->name);
    }
}
