/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestGameCalcVectorNorm, SimpleTest)
{
    pos_t map_size = {10, 10};
    pos_t a = {1, 4};
    pos_t b = {7, 2};

    vector_t *res = game_calc_vector_norm(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 4);
    EXPECT_EQ(res->y, 2);

    free(res);
}

TEST(TestGameCalcVectorNorm, DifferentPathTest)
{
    pos_t map_size = {10, 10};
    pos_t a = {3, 9};
    pos_t b = {7, 6};

    vector_t *res = game_calc_vector_norm(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, -4);
    EXPECT_EQ(res->y, 3);

    free(res);
}

TEST(TestGameCalcVectorNorm, SameCoord)
{
    pos_t map_size = {10, 10};
    pos_t a = {5, 5};
    pos_t b = {5, 5};

    vector_t *res = game_calc_vector_norm(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 0);
    EXPECT_EQ(res->y, 0);

    free(res);
}

TEST(TestGameCalcVectorNorm, SameAxe)
{
    pos_t map_size = {10, 10};
    pos_t a = {5, 4};
    pos_t b = {5, 8};

    vector_t *res = game_calc_vector_norm(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 0);
    EXPECT_EQ(res->y, -4);

    free(res);
}
