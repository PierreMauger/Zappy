/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *put_uuid_in_buff(list_t *uuids, char *buff)
{
    node_t *node = NULL;
    char *uuid = NULL;
    char *temp = NULL;

    foreach(uuids->head, node) {
        uuid = (char *)node->data;
        temp = buff;
        if (asprintf(&buff, "%s %s", buff, uuid) == -1) {
            fprintf(stderr, "[ERROR] GUI Can't malloc\n");
            return NULL;
        }
        free(temp);
    }
    temp = buff;
    if (asprintf(&buff, "%s\n", buff) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return NULL;
    }
    free(temp);
    return buff;
}

void command_pic(core_t *core, trantorian_t *trantorian, list_t *uuids)
{
    char *buff = NULL;

    if (asprintf(&buff, "pic %ld %ld %ld %s",
            trantorian->x,
            trantorian->y,
            trantorian->level,
            trantorian->uuid) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    buff = put_uuid_in_buff(uuids, buff);
    if (buff == NULL)
        return;
    client_gui_broadcast_command(core->server, buff);
}
