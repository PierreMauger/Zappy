/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef MAP_H
    #define MAP_H

    #define GET_CELL(map_ptr, x, y) (map_ptr->map[y * map_ptr->width + x])

    #include <stdio.h>

    #include "inventory.h"

typedef struct {
    inventory_t **map;
    size_t width;
    size_t height;
} map_t;

map_t *map_create(size_t width, size_t height);
void map_destroy(map_t *map);

#endif // MAP_H
