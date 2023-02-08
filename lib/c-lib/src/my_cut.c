/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** my_cut
*/

#include "c_lib.h"

int do_conditions(char *str, char *sub_str, int index, int *sub_index)
{
    int sub_str_len = my_strlen(sub_str);

    if (str[index] == sub_str[(*sub_index)]) {
        if ((*sub_index) == sub_str_len - 1)
            return (index - (*sub_index));
        (*sub_index)++;
    } else
        (*sub_index) = 0;
    return (-1);
}

int my_cut(char *str, char *sub_str)
{
    int index = 0;
    int sub_index = 0;
    int temp = -2;

    while (str[index]) {
        temp = do_conditions(str, sub_str, index, &sub_index);
        if (temp != -1)
            return (temp);
        index++;
    }
    return (0);
}
