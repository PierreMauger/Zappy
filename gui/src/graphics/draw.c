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
    "gui/resources/deraumere.png",
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

static const char *items[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    NULL
};

int string_to_number_object(map_t map, const char *object_name)
{
    if (strcmp(object_name, "food") == 0)
        return map.inv->food;
    if (strcmp(object_name, "linemate") == 0)
        return map.inv->linemate;
    if (strcmp(object_name, "deraumere") == 0)
        return map.inv->deraumere;
    if (strcmp(object_name, "sibur") == 0)
        return map.inv->sibur;
    if (strcmp(object_name, "mendiane") == 0)
        return map.inv->mendiane;
    if (strcmp(object_name, "phiras") == 0)
        return map.inv->phiras;
    if (strcmp(object_name, "thystame") == 0)
        return map.inv->thystame;
    return 0;
}

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
    for (node_t *i = tile.player->head; i; i = i->next) {
        DrawTexturePro(get_textures()[7 +
            ((player_t *)i->data)->level],
        (Rectangle){0, 0, 25, 30},
        (Rectangle){position.x, position.y, ratio, ratio},
        (Vector2){0, 0}, 0, RAYWHITE);
    }
}

void draw_inventory(client_t *client, pos_t size, pos_t edge)
{
    Vector2 pos = GetMousePosition();
    pos_t tile = {floorf((pos.x - edge.x) * client->size_map.x / size.x),
        floorf((pos.y - edge.y) * client->size_map.y / size.y)};

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (0 <= tile.x && tile.x < client->size_map.x &&
            0 <= tile.y && tile.y < client->size_map.y)
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
                for (int level = 1, tmp = 0; level <= 7; level++, tmp = 0) {
                    DrawTexturePro(get_textures()[7 + level],
                    (Rectangle){64, 32 + (int)(GetTime() * 10) % 3 * 31, 25, 30},
                    (Rectangle){0, level * 30 * 3, 25 * 3, 30 * 3},
                    (Vector2){0, 0}, 0, RAYWHITE);
                    for (node_t *k = client->map[y][x].player->head; k; k = k->next)
                        if (((player_t *)k->data)->level == level)
                            tmp++;
                    DrawText(TextFormat("x%d", tmp), 25 * 3, level * 30 * 3, 30, BLACK);
                }
                for (int item = 1; item <= 7; item++) {
                    DrawTexturePro(get_textures()[item],
                    (Rectangle){0, 0, 16, 16},
                    (Rectangle){edge.x + size.x, item * 16 * 4, 16 * 4, 16 * 4},
                    (Vector2){0, 0}, 0, RAYWHITE);
                    DrawText(TextFormat("x%d", string_to_number_object(client->map[y][x], items[item - 1])),
                    edge.x + size.x + 16 * 4, item * 16 * 4, 30, BLACK);
                }
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
