/*
** EPITECH PROJECT, 2022
** B-CPE-110-BAR-1-1-BSQ-joan-pau.merida-ruiz
** File description:
** count amount of \n in a string
*/

#include "c_lib.h"

int my_bsn_count(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            count++;
        i++;
    }
    return (count);
}
