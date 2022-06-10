/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestServerAlloc, Test1)
{
    server_t *server = server_create(8080, 4, 5);

    EXPECT_TRUE(server != nullptr);
    EXPECT_TRUE(server->port == 8080);
    EXPECT_TRUE(server->socket != nullptr);
    server_destroy(server);
}
