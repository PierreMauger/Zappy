/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestClientAlloc, Test1)
{
    client_t *client = client_create(0);

    EXPECT_TRUE(client != nullptr);
    EXPECT_TRUE(client->sock->fd == 0);
    client_destroy(client);
}
