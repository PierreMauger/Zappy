/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

void draw_items(map_t tile, pos_t pos, int ratio)
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
        if (ressource_pos->x == 0)
            ressource_pos->x = pos.x + (rand() % (ratio - 15));
        if (ressource_pos->y == 0)
            ressource_pos->y = pos.y + (rand() % (ratio - 15));
        DrawTexturePro(get_textures()[i + 1], (Rectangle){0, 0, 16, 16},
            (Rectangle){ressource_pos->x, ressource_pos->y, ratio / 5,
            ratio / 5}, (Vector2){0, 0}, 0, RAYWHITE);
    }
}
