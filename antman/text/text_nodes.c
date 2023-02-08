/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** nodes
*/

#include "antman_lib.h"

s_txtnode *init_structs(void)
{
    s_txtnode *node = malloc(sizeof(s_txtnode));

    node->order = 0;
    return (node);
}

s_txtnode *to_last_node(s_txtnode *node)
{
    if (node == NULL)
        return (node);
    while (node->next != NULL) {
        node = (node)->next;
    }
    return (node);
}

s_txtnode *create_nodes(s_txtnode *last, char *word, int len, int ascii)
{
    last->next = init_structs();
    last->next->word = my_strdup(word);
    last->next->order = 1;
    last->next->ascii = (char)ascii;
    last->next->next = NULL;
    last->next->previus = last;
    return (last->next);
}

s_txtnode *create_head_node(s_txtnode *node, char *word, int len)
{
    node->word = my_strdup(word);
    node->order = 1;
    node->ascii = 32;
    node->next = NULL;
    node->previus = NULL;
    return (node);
}
