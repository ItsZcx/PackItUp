/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** init_text_info
*/

#include "antman_lib.h"

s_txtinfo *init_txt_info(void)
{
    s_txtinfo *info = malloc(sizeof(s_txtinfo));

    info->cut = 0;
    info->index = 0;
    info->index2 = 0;
    info->repeat = 0;
    info->ascii = 33;
    return (info);
}
