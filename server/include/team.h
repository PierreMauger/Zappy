/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef TEAM_H
    #define TEAM_H

    #include <uuid/uuid.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

typedef struct {
    char *name;
    uuid_t id;
} team_t;

team_t *team_create(char *name);
void team_destroy(team_t *team);

#endif // TEAM_H
