/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

CommandFixture::CommandFixture(void)
{
    args_t *args = init_args();

    args->height = 3;
    args->width = 3;
    args->teams = (char **)calloc(2, sizeof(char *));
    args->teams[0] = strdup("team1");

    this->coreCreate(args);
    destroy_args(args);

    list_push_data(core->game->trantorians, trantorian_create((team_t *)this->core->game->teams->head->data, 1, 1));

    this->client = client_create(0);
    this->client->trantorian = (trantorian_t *)this->core->game->trantorians->head->data;
    this->client->type = CLI_GUI;

    list_push_data(core->server->clients, this->client);
}

CommandFixture::~CommandFixture(void)
{
    core_destroy(this->core);
}

void CommandFixture::coreCreate(args_t *args)
{
    this->core = core_create();
    if (this->core == nullptr)
        throw std::runtime_error("core_init failed");
    this->core->game = game_create(args->teams, args->width, args->height,
        args->cli_per_team);
    this->core->game->freq = args->freq;

    this->core->server = (server_t *)calloc(1, sizeof(server_t));
    if (this->core->server == NULL)
        throw std::runtime_error("core_init failed");
    this->core->server->port = args->port;
    this->core->server->socket = nlib_create_socket();
    this->core->server->clients = list_create();
    this->core->server->commands_to_send = list_create();
    if (this->core->server->socket == NULL ||
            this->core->server->clients == NULL ||
            this->core->server->commands_to_send == NULL)
        throw std::runtime_error("core_init failed");
    this->core->server->socket->fd = -1;
}

void CommandFixture::startTest(void)
{
    pipe(this->pipefd);
    this->client->sock->fd = this->pipefd[1];
}

void CommandFixture::endTest(void)
{
    char buffer[1024] = {0};

    FD_SET(pipefd[1], &writefds);
    FD_SET(pipefd[0], &readfds);

    nlib_select_fds(nullptr, &this->writefds);
    nlib_commands_update(this->core->server->commands_to_send, &this->writefds);
    nlib_select_fds_time(&this->readfds, nullptr, 0.1f);
    if (FD_ISSET(this->pipefd[0], &readfds)) {
        read(this->pipefd[0], buffer, 1024);
        this->res = buffer;
    }
    close(pipefd[0]);
    close(pipefd[1]);
}

std::string CommandFixture::getRes(void)
{
    return this->res;
}

core_t *CommandFixture::getCore(void)
{
    return this->core;
}

client_t *CommandFixture::getClient(void)
{
    return this->client;
}
