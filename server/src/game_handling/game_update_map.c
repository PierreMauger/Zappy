/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static const double density[] = {
    0.5,
    0.3,
    0.15,
    0.1,
    0.1,
    0.08,
    0.05
};

static void game_init_map_content(map_t *map, inventory_t *map_content)
{
    for (size_t i = 0; i < RESSOURCES_NBR; i++)
        ((size_t *)map_content)[i] =
            (size_t)((double)(map->width * map->height) * density[i]);
}

static void game_map_add_ressource(map_t *map, size_t ressource, size_t tile)
{
    ((size_t *)(map->map[tile]))[ressource]++;
}

static void game_dispatch(map_t *map, pos_t **map_content,
    size_t remaining_tiles, inventory_t *nb_ressources)
{
    size_t amount = 0;
    int random_idx = 0;

    for (size_t ressource = 0; ressource < RESSOURCES_NBR; ressource++) {
        amount = ((size_t *)(nb_ressources))[ressource];
        for (size_t remain = 0; remain < amount; remain++) {
            random_idx = rand() % remaining_tiles;
            game_map_add_ressource(map, ressource, GET_COORD(map,
                map_content[random_idx]->x, map_content[random_idx]->y));
            game_map_dup_delete_idx(map_content, random_idx, remaining_tiles);
            remaining_tiles--;
        }
        map_content = game_reset_map_dup(map, map_content);
        remaining_tiles = map->width * map->height;
    }
    game_destroy_map_dup(map, map_content);
}

void game_dispatch_ressources(map_t *map)
{
    pos_t **map_content = game_init_map_dup(map);
    size_t remaining_tiles = map->width * map->height;
    inventory_t nb_ressources = {0};

    if (map_content == NULL) {
        fprintf(stderr, "[ERROR] Failed to allocate map content\n");
        return;
    }
    game_init_map_content(map, &nb_ressources);
    game_dispatch(map, map_content, remaining_tiles, &nb_ressources);
}

void game_update_map(map_t *map)
{
    static size_t refresh = 1;

    refresh--;
    if (refresh > 0)
        return;
    refresh = MAP_REFRESH;
    printf("[INFO] Updating map\n");
    game_dispatch_ressources(map);
}
