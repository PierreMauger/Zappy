/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

void parse_map(client_t *client)
{
    for (int i = 0; i < client->size_map.y; i++) {
        for (int j = 0; j < client->size_map.x; j++) {

        }
    }
}

void draw_map(client_t *client)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    parse_map(client);
    EndDrawing();
}