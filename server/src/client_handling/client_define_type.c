/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *get_client_num(core_t *core, team_t *team)
{
    char *buffer = NULL;
    int nb = (core->game->cli_per_team - team->cli_sub) + 1;

    if (asprintf(&buffer, "%d\n", nb) == -1)
        return NULL;
    return buffer;
}

static char *get_map_size(map_t *map)
{
    char *buffer = NULL;

    if (asprintf(&buffer, " %ld %ld\n", map->height, map->width) == -1)
        return NULL;
    return buffer;
}

static int client_create_new_trantorian(core_t *core, client_t *client,
    team_t *team)
{
    client->type = CLI_DEFAULT;
    client->trantorian = trantorian_create(team,
        core->game->map->width, core->game->map->height, true);
    if (client->trantorian == NULL)
        return ERROR;
    list_push_data(core->game->trantorians, client->trantorian);
    client->trantorian->client = client;
    return SUCCESS;
}

static void client_define_default(core_t *core, client_t *client,
    char *command)
{
    team_t *team = team_get_obj(core->game->teams, command);

    if (team == NULL) {
        fprintf(stderr, "[ERROR] Team \"%s\" does not exist\n", command);
        printf("[INFO] Client kicked\n");
        list_destroy_data_node(core->server->clients, client,
            (void (*)(void *))client_destroy);
        return;
    }
    if (client_create_new_trantorian(core, client, team) == ERROR) {
        fprintf(stderr, "[ERROR] Can't create trantorian\n");
        printf("[INFO] Client connection closed\n");
        list_destroy_data_node(core->server->clients, client,
            (void (*)(void *))client_destroy);
        return;
    }
    client->trantorian->state = TRANT_LIVING;
    client_push_command(core->server, client, get_client_num(core, team));
    client_push_command(core->server, client, get_map_size(core->game->map));
    printf("[INFO] Default client detected\n");
    command_pnw(core, client->trantorian);
}

void client_define_type(core_t *core, client_t *client, char *command)
{
    if (is_uuid(command)) {
        client->type = CLI_GUI;
        printf("[INFO] GUI client detected\n");
        return;
    }
    client_define_default(core, client, command);
}
