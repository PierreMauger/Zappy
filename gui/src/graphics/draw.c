/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

static const char *paths[] = {
    "deraumer.png",
    "grass.png",
    "linemate.png",
    "mendiane.png",
    "phiras.png",
    "sibur.png",
    "thystame.png",
    "1.png",
    "2.png",
    "3.png",
    "4.png",
    "5.png",
    "6.png",
    "7.png",
    NULL
};

Texture *getTextures()
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

void unloadTextures(Texture *textures)
{
    for (size_t i = 0; paths[i]; i++)
        UnloadTexture(textures[i]);
    free(textures);
}

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
    unloadTextures(getTextures());
    EndDrawing();
}