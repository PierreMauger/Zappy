/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestRandom, Test1)
{
    EXPECT_TRUE(inventory_create() != NULL);
}
