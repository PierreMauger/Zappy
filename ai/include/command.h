/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** include
*/

#ifndef COMMAND_H
    #define COMMAND_H

    #include <stdlib.h>

typedef struct client_s client_t;

int forward_movement(client_t *client, char *str);
int right_movement(client_t *client, char *str);
int left_movement(client_t *client, char *str);
int look_around(client_t *client, char *str);
int inventory(client_t *client, char *str);
int broadcast(client_t *client, char *str);
int connect_nbr(client_t *client, char *str);
int fork_player(client_t *client, char *str);
int eject_player(client_t *client, char *str);
int take_object(client_t *client, char *str);
int set_object(client_t *client, char *str);
int incantation(client_t *client, char *str);

typedef struct com_s {
    const char *cmd;
    int (*func_ptr)(client_t *client, char *str);
} com_t;

static const com_t com[] =
{
    {"Forward\n\0", &forward_movement},
    {"Right\n\0", &right_movement},
    {"Left\n\0", &left_movement},
    {"Look\n\0", &look_around},
    {"Inventory\n\0", &inventory},
    {"Broadcast text\n\0", &broadcast},
    {"Connect_nbr\n\0", &connect_nbr},
    {"Fork\n\0", &fork_player},
    {"Eject\n\0", &eject_player},
    {"Take object\n\0", &take_object},
    {"Set object\n\0", &set_object},
    {"Incantation\n\0", &incantation},
    {NULL, NULL}
};

#endif
