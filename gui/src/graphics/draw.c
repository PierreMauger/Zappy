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

void draw_player(map_t tile, int ratio, Vector2 position)
{
    Texture texture;

    if (tile.player) {
        texture = get_textures()[7 + tile.player->level];
        DrawTexturePro(texture,
        (Rectangle){0, 0, texture.width, texture.width},
        (Rectangle){position.x, position.y, ratio, ratio},
        (Vector2){0, 0},
        0, WHITE);
    }
}

void draw_inventory(client_t *client, pos_t size, pos_t edge)
{
    Vector2 tile = {(GetMousePosition().x - edge.x) * client->size_map.x / size.x,
        (GetMousePosition().y - edge.y) * client->size_map.y / size.y};

    printf("%f %f\n", tile.x, tile.y);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

    }
}

void draw_map(client_t *client)
{
    pos_t size = {GetScreenWidth(), GetScreenHeight()};
    pos_t ratios = {size.x / client->size_map.x, size.y / client->size_map.y};
    int ratio = ratios.x < ratios.y ? ratios.x : ratios.y;
    pos_t edge = {(size.x - client->size_map.x * ratio) / 2,
        (size.y - client->size_map.y * ratio) / 2};

    for (int i = 0; i < client->size_map.y; i++) {
        for (int j = 0; j < client->size_map.x; j++) {
            DrawTexturePro(get_textures()[0],
            (Rectangle){0, 0, get_textures()[0].width, get_textures()[0].height},
            (Rectangle){edge.x + i * ratio, edge.y + j * ratio, ratio, ratio},
            (Vector2){0, 0}, 0, RAYWHITE);
            draw_player(client->map[i][j], ratio, (Vector2){edge.x + i * ratio,
            edge.y + j * ratio});
        }
    }
    draw_inventory(client, size, edge);
}

void draw_all(client_t *client)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_map(client);
    EndDrawing();
}
