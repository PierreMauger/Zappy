/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client gui
*/

#include "zappy_gui.h"

void free_player(void *data)
{
    if (data)
        free(data);
}
