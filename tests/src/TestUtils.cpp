/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestGameCalcVectorCoord, SimpleTest)
{
    pos_t map_size = {10, 10};
    pos_t a = {1, 4};
    pos_t b = {7, 2};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 4);
    EXPECT_EQ(res->y, 2);

    free(res);
}

TEST(TestGameCalcAngle, Basic)
{
    vector_t vect = {-5, 1};

    size_t res = game_calc_angle_degrees(&vect);

    EXPECT_EQ(res, 11);
}

TEST(TestGameCalcVectorCoord, DifferentPathTest)
{
    pos_t map_size = {10, 10};
    pos_t a = {3, 9};
    pos_t b = {7, 6};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, -4);
    EXPECT_EQ(res->y, 3);

    free(res);
}

TEST(TestGameCalcVectorCoord, InvertCoord)
{
    pos_t map_size = {10, 10};
    pos_t a = {7, 6};
    pos_t b = {3, 9};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 4);
    EXPECT_EQ(res->y, -3);

    free(res);
}

TEST(TestGameCalcVectorCoord, SameCoord)
{
    pos_t map_size = {10, 10};
    pos_t a = {5, 5};
    pos_t b = {5, 5};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 0);
    EXPECT_EQ(res->y, 0);

    free(res);
}

TEST(TestGameCalcVectorCoord, SameAxe)
{
    pos_t map_size = {10, 10};
    pos_t a = {5, 4};
    pos_t b = {5, 8};

    vector_t *res = game_calc_vector(map_size.x, map_size.y, &a, &b);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->x, 0);
    EXPECT_EQ(res->y, -4);

    free(res);
}

TEST(TestGameCalcAngle, RightUp)
{
    vector_t vect = {2, 1};

    size_t res = game_calc_angle_degrees(&vect);

    EXPECT_EQ(res, 26);
}

TEST(TestGameCalcAngle, RightDown)
{
    vector_t vect = {2, -1};

    size_t res = game_calc_angle_degrees(&vect);

    EXPECT_EQ(res, 26);
}

TEST(TestGameCalcAngle, LeftDown)
{
    vector_t vect = {-2, -1};

    size_t res = game_calc_angle_degrees(&vect);

    EXPECT_EQ(res, 26);
}

TEST(TestGameCalcAngle, LeftUp)
{
    vector_t vect = {-2, 1};

    size_t res = game_calc_angle_degrees(&vect);

    EXPECT_EQ(res, 26);
}
