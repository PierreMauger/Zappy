/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "list.h"

list_t *list_create(void)
{
    return calloc(sizeof(list_t), 1);
}

void list_destroy(list_t *list, void (*destroy_data)(void *data))
{
    node_t *node = NULL;
    node_t *node_safe = NULL;

    if (list == NULL)
        return;
    foreach_safe(list->head, node, node_safe) {
        list_destroy_node(node, destroy_data);
    }
    free(list);
}
