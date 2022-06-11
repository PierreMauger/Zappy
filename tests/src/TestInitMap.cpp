/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestMapAlloc, Test1)
{
    map_t *map = map_create(5, 5);

    EXPECT_TRUE(map != nullptr);
    EXPECT_TRUE(map->map != nullptr);
    map_destroy(map);
}
