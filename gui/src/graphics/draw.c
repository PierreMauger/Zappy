/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

static const char *paths[] = {
    "gui/resources/grass.png",
    "gui/resources/chicken.png",
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

void draw_player(map_t tile, int ratio, pos_t position)
{
    if (tile.player) {
        DrawTexturePro(get_textures()[8 + tile.player->level],
        (Rectangle){0, 0, 25, 30},
        (Rectangle){position.x, position.y, ratio, ratio},
        (Vector2){0, 0},
        0, WHITE);
    }
}

void draw_inventory(client_t *client, pos_t size, pos_t edge)
{
    Vector2 pos = GetMousePosition();
    pos_t tile = {(pos.x - edge.x) * client->size_map.x / size.x,
        (pos.y - edge.y) * client->size_map.y / size.y};

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && 0 <= tile.x && tile.x <
        client->size_map.x && 0 <= tile.y && tile.y < client->size_map.y) {
        client->map[tile.y][tile.x].clicked = !client->map[tile.y][tile.x].clicked;
        for (int y = 0; y < client->size_map.y; y++)
            for (int x = 0; x < client->size_map.x; x++)
                if (!(y == tile.y && x == tile.x))
                    client->map[y][x].clicked = false;
    }
    for (int y = 0; y < client->size_map.y; y++)
        for (int x = 0; x < client->size_map.x; x++)
            if (client->map[y][x].clicked) {
                DrawText(TextFormat("Tile [%d;%d]", y, x), 0, 0, 30, BLACK);
                DrawText(TextFormat("Tile [%d;%d]", y, x), edge.x + size.x, 0, 30, BLACK);
                // for (int level = 1; level <= 7; level++) {
                //     DrawTexturePro(get_textures()[8 + level], )
                // }
                return;
            }
}
    

void draw_map(client_t *client)
{
    pos_t size = {GetScreenWidth(), GetScreenHeight()};
    pos_t ratios = {size.x / client->size_map.x, size.y / client->size_map.y};
    int ratio = ratios.x < ratios.y ? ratios.x : ratios.y;
    pos_t edge = {(size.x - client->size_map.x * ratio) / 2,
        (size.y - client->size_map.y * ratio) / 2};

    for (int y = 0; y < client->size_map.y; y++) {
        for (int x = 0; x < client->size_map.x; x++) {
            DrawTexturePro(get_textures()[0],
            (Rectangle){0, 0, get_textures()[0].width, get_textures()[0].height},
            (Rectangle){edge.x + x * ratio, edge.y + y * ratio, ratio, ratio},
            (Vector2){0, 0}, 0, RAYWHITE);
            draw_player(client->map[y][x], ratio, (pos_t){edge.x + x * ratio,
            edge.y + y * ratio});
        }
    }
    draw_inventory(client,
        (pos_t){client->size_map.x * ratio, client->size_map.y * ratio}, edge);
}

void draw_all(client_t *client)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_map(client);
    EndDrawing();
}
