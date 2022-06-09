/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestGameAlloc, Test1)
{
    game_t *game = game_create(NULL, 0, 0, 0);

    EXPECT_TRUE(game != nullptr);
    game_destroy(game);
}
