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

int core_init(core_t *core, args_t *args);

typedef struct command_handler_s {
    char *params;
    void (*command)(core_t *core, client_t *client, char *command);
    int command_it;
} command_handler_t;

command_handler_t *handler_create(void);
void handler_clear(command_handler_t *handler);

args_t *init_args(void);
void destroy_args(args_t *args);

int verif_params(args_t *args);
int parse_params(int argc, char **argv, args_t *args);

bool is_uuid(char *str);
team_t *team_get_obj(list_t *teams, const char *to_comp);

void set_read_fds(server_t *serv, fd_set *fds);
void set_write_fds(server_t *serv, fd_set *fds);

typedef struct {
    char *name;
    void (*func)(core_t *core, client_t *client, char *command);
} method_t;

char *command_write_tile_content(core_t *core, client_t *client,
    size_t x, size_t y);

void command_msz(core_t *core, client_t *client, char *command);
void command_bct(core_t *core, client_t *client, char *command);
void command_mct(core_t *core, client_t *client, char *command);
void command_tna(core_t *core, client_t *client, char *command);
void command_ppo(core_t *core, client_t *client, char *command);
void command_plv(core_t *core, client_t *client, char *command);
void command_pin(core_t *core, client_t *client, char *command);
void command_sgt(core_t *core, client_t *client, char *command);
void command_sst(core_t *core, client_t *client, char *command);
void command_pnw(core_t *core, trantorian_t *trantorian);
void command_pex(core_t *core, trantorian_t *trantorian);
void command_pbc(core_t *core, trantorian_t *trantorian, char *message);
void command_pic(core_t *core, trantorian_t *trantorian, list_t *uuids);
void command_pie(core_t *core, trantorian_t *trantorian);
void command_pfk(core_t *core, trantorian_t *trantorian);
void command_pdr(core_t *core, trantorian_t *trantorian, size_t nb_drop);
void command_pgt(core_t *core, trantorian_t *trantorian, size_t nb_get);
void command_pdi(core_t *core, trantorian_t *trantorian);
void command_enw(core_t *core, trantorian_t *trantorian, trantorian_t *egg);
void command_eht(core_t *core, trantorian_t *egg);
void command_ebo(core_t *core, trantorian_t *egg);
void command_edi(core_t *core, trantorian_t *egg);
void command_seg(core_t *core, team_t *team_winner);
void command_smg(core_t *core, char *message);
void command_suc(core_t *core, client_t *client);
void command_sbp(core_t *core, client_t *client);

void client_gui_search_command(core_t *core, client_t *client, char *command);

void command_forward(core_t *core, client_t *client, char *command);
void forward_e(core_t *core, client_t *client, char *command);

void command_right(core_t *core, client_t *client, char *command);
void right_e(core_t *core, client_t *client, char *command);

void command_left(core_t *core, client_t *client, char *command);
void left_e(core_t *core, client_t *client, char *command);

void command_look(core_t *core, client_t *client, char *command);
void look_e(core_t *core, client_t *client, char *command);

void command_inventory(core_t *core, client_t *client, char *command);
void inventory_e(core_t *core, client_t *client, char *command);

void command_broadcast(core_t *core, client_t *client, char *command);
void broadcast_e(core_t *core, client_t *client, char *command);

void command_connect_nbr(core_t *core, client_t *client, char *command);

void command_fork(core_t *core, client_t *client, char *command);
void fork_e(core_t *core, client_t *client, char *command);

void command_eject(core_t *core, client_t *client, char *command);
void eject_e(core_t *core, client_t *client, char *command);

void command_take(core_t *core, client_t *client, char *command);
void take_e(core_t *core, client_t *client, char *command);

void command_set(core_t *core, client_t *client, char *command);
void set_e(core_t *core, client_t *client, char *command);

void command_incantation(core_t *core, client_t *client, char *command);
void incantation_e(core_t *core, client_t *client, char *command);

void command_death(core_t *core, client_t *client, char *command);

void client_def_search_command(core_t *core, client_t *client, char *command);

void client_define_type(core_t *core, client_t *client, char *command);

void client_push_command(server_t *serv, client_t *client, char *buff);
void client_def_broadcast_command(server_t *serv, char *buff);
void client_gui_broadcast_command(server_t *serv, char *buff);
void client_exec_command(core_t *core, client_t *client);
void client_push_exec_command(client_t *client, char *buffer);
int client_get_command(client_t *client);
void clients_update(core_t *core, fd_set *readfds);

int server_start(args_t *args);
int server_loop(core_t *core);

void game_remove_trantorian(core_t *core, trantorian_t *trantorian);

void game_update_handler(core_t *core, client_t *client);
void game_update_handlers(core_t *core);
void game_update_trantorians(core_t *core);
bool game_clock_update(size_t freq);
void game_update(core_t *core);

vector_t *game_calc_vector_norm(size_t map_x, size_t map_y,
    pos_t *a, pos_t *b);

#endif // CORE_H
