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

int bct(client_t *client, char *str);
int mct(client_t *client, char *str);
int msz(client_t *client, char *str);
int ppo(client_t *client, char *str);
int pdi(client_t *client, char *str);
int pin(client_t *client, char *str);
int pnw(client_t *client, char *str);
int plv(client_t *client, char *str);
int tna(client_t *client, char *str);
int sgt(client_t *client, char *str);

typedef struct com_s {
    const char *cmd;
    int (*func_ptr)(client_t *client, char *str);
} com_t;

static const com_t com[] =
{
    {"bct\0", &bct},
    {"mct\0", &mct},
    {"msz\0", &msz},
    {"ppo\0", &ppo},
    {"plv\0", &plv},
    {"pin\0", &pin},
    {"pdi\0", &pdi},
    {"pnw\0", &pnw},
    {"tna\0", &tna},
    {"sgt\0", &sgt},
    {NULL, NULL}
};

#endif
