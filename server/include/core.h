/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef CORE_H
    #define CORE_H

    #define DEFAULT_PORT (8080)
    #define DEFAULT_WIDTH (10)
    #define DEFAULT_HEIGHT (10)
    #define DEFAULT_FREQ (100)

    #define ERROR_EXIT (84)

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <regex.h>

    #include "list.h"
    #include "nlib.h"

    #include "server.h"
    #include "game.h"
    #include "client.h"

typedef struct {
    int port;
    size_t width;
    size_t height;
    size_t cli_per_team;
    size_t freq;
    char **teams;
} args_t;

typedef struct {
    server_t *server;
    game_t *game;
} core_t;

core_t *core_create(void);
void core_destroy(core_t *core);

args_t *init_args(void);
void destroy_args(args_t *args);

int verif_params(args_t *args);
int parse_params(int argc, char **argv, args_t *args);

bool is_uuid(char *str);
team_t *team_get_obj(list_t *teams, char *to_comp);

void set_read_fds(server_t *serv, fd_set *fds);
void set_write_fds(server_t *serv, fd_set *fds);

typedef struct {
    char *name;
    void (*func)(core_t *core, client_t *client);
} method_t;

void command_msz(core_t *core, client_t *client);
void command_bct(core_t *core, client_t *client);
void command_mct(core_t *core, client_t *client);
void command_tna(core_t *core, client_t *client);
void command_ppo(core_t *core, client_t *client);
void command_plv(core_t *core, client_t *client);
void command_pin(core_t *core, client_t *client);
void command_sgt(core_t *core, client_t *client);
void command_sst(core_t *core, client_t *client);

void client_gui_search_command(core_t *core, client_t *client, char *command);

void command_forward(core_t *core, client_t *client);
void command_right(core_t *core, client_t *client);
void command_left(core_t *core, client_t *client);
void command_look(core_t *core, client_t *client);
void command_inventory(core_t *core, client_t *client);
void command_broadcast(core_t *core, client_t *client);
void command_connect_nbr(core_t *core, client_t *client);
void command_fork(core_t *core, client_t *client);
void command_eject(core_t *core, client_t *client);
void command_take(core_t *core, client_t *client);
void command_set(core_t *core, client_t *client);
void command_incantation(core_t *core, client_t *client);

void client_def_search_command(core_t *core, client_t *client, char *command);

void client_define_type(core_t *core, client_t *client, char *command);

void client_push_command(server_t *serv, client_t *client,
    char *buff, bool broadcast);
void client_exec_command(core_t *core, client_t *client);
void client_push_exec_command(client_t *client, char *buffer);
int client_get_command(client_t *client);
void clients_update(core_t *core, fd_set *readfds);

int server_start(args_t *args);
int server_loop(core_t *core);

#endif // CORE_H
