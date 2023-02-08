/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** decompress_image
*/

#include "giantman_lib.h"

int do_print_text(text_g *text, int pos)
{
    int num = 0;
    int setter = 0;

    while (text->dictionary[num]) {
        if (text->buf[pos] == text->dictionary[num]->ascii[0]) {
            my_putstr(text->dictionary[num]->color);
            text->setter = num;
        }
        num++;
    }
    return (pos);
}

int get_descompressor_text(text_g *text)
{
    int index = 0;
    int checker = 2;

    while (text->buf[index] != '\0' && text->buf[index + 4] != ';') {
        if (text->buf[index] == '_' && checker > 1
            || index < 1 && text->buf[index] == '_') {
            do_print_text(text, index + 1);
            checker = 0;
        }
        if (text->buf[index] != '_' && checker > 1)
            my_putchar(text->buf[index]);
        checker++;
        index++;
    }
    return (0);
}

int get_separators_text(text_g *text)
{
    int index = 0;

    while (text->buf[index] != '\0') {
        if (text->buf[index] == '\n' && text->buf[index + 1] == '|')
            get_dictionary_text(text, index + 1);
        index++;
    }
    return (0);
}
