/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_death(core_t *core, client_t *client, UNUSED char *command)
{
    client_push_command(core->server, client, strdup("dead\n"));
}
