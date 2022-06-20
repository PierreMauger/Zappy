/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

static const char *paths[] = {
    "gui/resources/grass.png",
    "gui/resources/linemate.png",
    "gui/resources/deraumer.png",
    "gui/resources/sibur.png",
    "gui/resources/mendiane.png",
    "gui/resources/phiras.png",
    "gui/resources/thystame.png",
    "gui/resources/1.png",
    "gui/resources/2.png",
    "gui/resources/3.png",
    "gui/resources/4.png",
    "gui/resources/5.png",
    "gui/resources/6.png",
    "gui/resources/7.png",
    NULL
};

Texture *get_textures()
{
    static Texture *textures = NULL;
    size_t length = 0;

    if (!textures) {
        for (; paths[length]; length++);
        textures = malloc(sizeof(Texture) * length);
        for (size_t i = 0; i < length; i++)
            textures[i] = LoadTexture(paths[i]);
    }
    return textures;
}

void unload_textures(Texture *textures)
{
    for (size_t i = 0; paths[i]; i++)
        UnloadTexture(textures[i]);
    free(textures);
}

void parse_map(client_t *client)
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    int ratio_x = width / client->size_map.x;
    int ratio_y = height / client->size_map.y;
    int ratio = ratio_x < ratio_y ? ratio_x : ratio_y;

    for (int i = 0; i < client->size_map.y; i++) {
        for (int j = 0; j < client->size_map.x; j++) {
            DrawTexturePro(get_textures()[0], (Rectangle){0, 0, 16, 16},
            (Rectangle){i * ratio, j * ratio, ratio, ratio},
            (Vector2){0, 0}, 0, RAYWHITE);
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
