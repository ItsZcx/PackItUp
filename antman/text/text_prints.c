/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** text_prints
*/

#include "antman_lib.h"

bool already_in_list(s_txtnode *node, char *str)
{
    s_txtnode *temp = node;

    while (temp->previus != NULL) {
        if (my_strcmp(temp->word, str) == 0)
            return (true);
        temp = temp->previus;
    }
    return (false);
}

int already_in_list_2(s_txtnode *node, char *arr_i)
{
    int cut = 0;
    int strlen_arr_i = 0;
    s_txtnode *temp = node;

    while (temp->previus != NULL) {
        if (my_cut(arr_i, temp->word) != 0) {
            cut = my_cut(arr_i, temp->word);
            print_start_word(cut, arr_i);
            my_putchar('_');
            my_putchar(temp->ascii);
            temp->order = 2;
            strlen_arr_i = my_strlen(arr_i);
            print_end_word_condition(cut, strlen_arr_i, arr_i, temp);
            return (1);
        }
        temp = temp->previus;
    }
    return (0);
}

void print_ascii(s_txtnode *node, char *str)
{
    s_txtnode *temp = node;

    while (temp->previus != NULL) {
        if (my_strcmp(temp->word, str) == 0) {
            my_putchar('_');
            my_putchar(temp->ascii);
        }
        temp = temp->previus;
    }
}

s_txtnode *print_dictionary(s_txtnode *node)
{
    if (node == NULL)
        return (node);
    while (node->previus != NULL) {
            my_putchar(';');
            my_putstr(node->word);
            my_putchar('_');
            my_putchar(node->ascii);
        node = node->previus;
    }
    return (node);
}
