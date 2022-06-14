/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#ifndef GOOGLE_TESTS_HPP
    #define GOOGLE_TESTS_HPP

    #include <gtest/gtest.h>

    extern "C" {
        #include "client.h"
        #include "core.h"
        #include "game.h"
        #include "inventory.h"
        #include "map.h"
        #include "server.h"
        #include "team.h"
        #include "trantorian.h"
    }

class SimulateCommand
{
    public:
        SimulateCommand();
        ~SimulateCommand();

        void coreCreate(args_t *args);

        void startTest(void);
        void endTest(void);

        std::string getRes(void);

        core_t *getCore(void);
        client_t *getClient(void);

    private:
        core_t *core;
        client_t *client;

        int pipefd[2] = {0};
        fd_set writefds = {0};
        fd_set readfds = {0};
        std::string res;
};

#endif /* GOOGLE_TESTS_HPP */
