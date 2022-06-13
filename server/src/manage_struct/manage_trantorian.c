/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "trantorian.h"

static char *trantorian_get_uuid(void)
{
    uuid_t temp = {0};
    char *buff = NULL;

    uuid_generate_time_safe(temp);
    buff = calloc(sizeof(unsigned char), UUID_STR_LEN);
    if (buff == NULL)
        return NULL;
    uuid_unparse(temp, buff);
    return buff;
}

trantorian_t *trantorian_create(team_t *team, size_t map_x, size_t map_y)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    if (!trantorian)
        return NULL;
    trantorian->uuid = trantorian_get_uuid();
    trantorian->team = team;
    trantorian->x = rand() % map_x;
    trantorian->y = rand() % map_y;
    trantorian->inventory = inventory_create();
    if (trantorian->inventory == NULL || trantorian->uuid == NULL) {
        trantorian_destroy(trantorian);
        return NULL;
    }
    trantorian->level = 1;
    trantorian->direction = rand() % DIR_SIZE;
    return trantorian;
}

void trantorian_destroy(trantorian_t *trantorian)
{
    if (trantorian == NULL)
        return;
    if (trantorian->uuid != NULL)
        free(trantorian->uuid);
    if (trantorian->inventory)
        inventory_destroy(trantorian->inventory);
    free(trantorian);
}
