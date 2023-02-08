/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** my_prints
*/

#include "antman_lib.h"

void print_everything_hardcoded(s_txtnode *node, char **arr,
s_txtinfo *info, int i)
{
    if (already_in_list_2(node, arr[i]) != 0) {
        info->index++;
    } else
        my_putstr(arr[i]);
}

void print_everything(s_txtnode *node, char **arr, s_txtinfo *info)
{
    int index = 0;

    while (arr[index]) {
        if (already_in_list(node, arr[index]) == false)
            print_everything_hardcoded(node, arr, info, index);
        else
            print_ascii(node, arr[index]);
        my_putchar(' ');
        index++;
    }
    my_putstr("\n|\n");
    node = print_dictionary(node);
}
