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
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    int ratio_x = width / client->size_map.x;
    int ratio_y = height / client->size_map.y;
    int ratio = ratio_x < ratio_y ? ratio_x : ratio_y;

    printf("%s%d %d%s\n", R, client->size_map.y, client->size_map.x, W);
    for (int i = 0; i < client->size_map.y; i++) {
        for (int j = 0; j < client->size_map.x; j++) {
            DrawRectangle(i * ratio, j * ratio, ratio, ratio, RED);
            DrawTexturePro(getTextures()[0],
            (Rectangle){0, 0, 16, 16},
            (Rectangle){i * ratio, j * ratio, ratio, ratio},
            // (Rectangle){0, 0, 16, 16},
            (Vector2){0, 0}, 0, WHITE);
            // DrawTexture(getTextures()[0], i * ratio, j * ratio, WHITE);
        }
    }
}

void draw_map(client_t *client)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    parse_map(client);
    unloadTextures(getTextures());
    EndDrawing();
}
