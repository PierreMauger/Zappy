/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static void print_usage(void)
{
    printf("USAGE: ");
    printf("./zappy_server -p port -x width -y height -n name1 name2 ... "
        "-c clientsNb -f freq\n");
    printf("   -p | --port\t\tport number\t\t\t(8080 by default)\n");
    printf("   -x | --width\t\tmap width\t\t\t(10 by default)\n");
    printf("   -y | --height\tmap height\t\t\t(10 by default)\n");
    printf("   -n | --name\t\tname of the team\n");
    printf("   -c | --clients\tnumber of client per team\t(1 by default)\n");
    printf("   -f | --freq\t\tcycle frequency\t\t\t(100 by default)\n");
}

int main(int argc, char **argv)
{
    args_t *args = init_args();

    if (args == NULL)
        return ERROR_EXIT;
    if (parse_params(argc, argv, args) == ERROR ||
        verif_params(args) == ERROR) {
        print_usage();
        destroy_args(args);
        return ERROR_EXIT;
    }

    return 0;
}
