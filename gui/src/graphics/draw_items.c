/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

void draw_items(map_t tile, pos_t pos)
{
    size_t ressource = 0;
    pos_t *ressource_pos = NULL;

    for (size_t i = 0; i < RESSOURCE_NBR; i++) {
        ressource = ((size_t *)(tile.inv))[i];
        ressource_pos = (pos_t *)(&((size_t *)(tile.inv))[RESSOURCE_NBR + i]);
        if (ressource == 0) {
            ressource_pos->x = 0;
            ressource_pos->y = 0;
            continue;
        }
        if (ressource_pos->x == 0) {
            ressource_pos->x = pos.x + (rand() % 58);
        }
        if (ressource_pos->y == 0) {
            ressource_pos->y = pos.y + (rand() % 58);
        }
        DrawTexture(get_textures()[i + 1], ressource_pos->x,
            ressource_pos->y, RAYWHITE);
    }
}
