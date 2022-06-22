/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** include
*/

#ifndef ZAPPY_AI_H
    #define ZAPPY_AI_H

    #ifndef _GNU_SOURCE
        #define _GNU_SOURCE
    #endif

    #define SUCCESS (0)
    #define ERROR (1)
    #define EXIT (2)

    #define ERROR_EXIT (84)

    #define UNUSED __attribute__((unused))

    #include <sys/types.h>
    #include <linux/limits.h>
    #include <sys/stat.h>

    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <regex.h>
    #include <fcntl.h>
    #include <signal.h>

    #include "list.h"
    #include "nlib.h"
    #include "command.h"

typedef enum {
    North,
    East,
    South,
    West
} direction_e;

typedef struct arg_s {
    int port;
    char *name;
    char *machine;
} arg_t;

typedef struct pps_s {
    int *x;
    int *y;
} pps_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

typedef struct player_s {
    char *team_name;
    char *uuid;
    size_t level;
    size_t number;
    size_t broadcast_direction;
    inventory_t *inv;
    pos_t pos;
    direction_e dir;
} player_t;

typedef struct map_s {
    inventory_t *inv;
    list_t *player;
    bool clicked;
} map_t;

typedef struct client_s {
    socket_t *socket;
    char *machine;
    pos_t size_map;
    bool init;
    bool client_connected;
    int unused_slot;
    fd_set readfds;
    fd_set writefds;
    list_t *command;
    list_t *pending_commands;
    list_t *received_commands;
    player_t *player;
    map_t **map;
} client_t;

    #define R "\033[1;31m"
    #define G "\033[1;32m"
    #define Y "\033[1;33m"
    #define B "\033[1;34m"
    #define M "\033[1;35m"
    #define C "\033[1;36m"
    #define W "\033[1;0m"

client_t *create_client(arg_t *arg);
void free_client(client_t *client);
bool init_client(arg_t *arg);

bool send_message(list_t *pending, list_t *list, socket_t *socket, char *mess);

int read_stdin(client_t *client);

bool parse_return(client_t *client, char *str);
bool loop_parse_return(client_t *client, char *temp);
bool client_push_exec_command(client_t *client, char *buffer);
bool message_broadcast(client_t *client, char *str);

void sig_handler(int signum);

bool ai(client_t *client);
bool path_finding_object(client_t *client, char *object);
bool go_to_next_object(client_t *client, int dest_x, int dest_y);
bool get_food_in_cell(client_t *client, size_t x, size_t y);
bool get_object(client_t *client, size_t nb, size_t needed, char *object);

int round_map(client_t *client, int pos, bool is_x);
void find_closest_round(client_t *client, int *dest_x, int *dest_y);

bool create_map(client_t *client);
map_t **copy_double_tab(map_t **map, size_t x, size_t y);
void free_player(player_t *player);
void free_map(client_t *client);
void free_map_copy(map_t **map, size_t x, size_t y);
int string_to_number_object(map_t map, char *object_name);

char *go_next_chr(char *str, char chr);
char *get_one_word(char *str);
char *get_cell(char *tab);
char *add_newline(char *str);
size_t change_pos(client_t *client, size_t v, size_t change_v, bool is_x);
int my_getnbr(char *str);

bool level_1(client_t *client);
bool level_2(client_t *client);
bool level_3(client_t *client);
bool level_4(client_t *client);
bool level_5(client_t *client);
bool level_6(client_t *client);
bool level_7(client_t *client);

void print_inventory(inventory_t *inv);
void print_inventory_map(client_t *client);
void print_dir(direction_e dir);

#endif // ZAPPY_AI_H
