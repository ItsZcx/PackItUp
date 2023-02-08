/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** decompress_image
*/

#include "giantman_lib.h"

int do_print(image_g *images, int pos)
{
    int num = 0;
    int index = 0;
    char *temp = malloc(sizeof(char) * 4);

    while (images->buf[pos] != 'x' && images->buf[pos] != ';'
        && images->buf[pos] != '\n') {
        temp[index] = images->buf[pos];
        pos++;
        index++;
    }
    temp[index] = '\0';
    while (images->dictionary[num]) {
        if (my_strcmp(temp, images->dictionary[num]->ascii) == 0) {
            my_putstr(images->dictionary[num]->color);
            images->setter = num;
            my_putchar('\n');
        }
        num++;
    }
    return (pos);
}

int get_color(image_g *images, int pos)
{
    int index = 0;
    int num_mult = 0;
    pos = do_print(images, pos);

    if (images->buf[pos] == 120) {
        pos++;
        images->prod = malloc(sizeof(my_ascii_length(images->buf, pos + 1)));
        while (images->buf[pos] != ';' && images->buf[pos] != '\n') {
            images->prod[index] = images->buf[pos];
            index++;
            pos++;
        }
        images->prod[index] = '\0';
        num_mult = my_get_nbr(images->prod);
        for (int j = 0; j < num_mult - 1; j++) {
            my_putstr(images->dictionary[images->setter]->color);
            my_putchar('\n');
        }
    }
}

int get_descompressor(image_g *images)
{
    int index = images->index;

    while (images->buf[index] != '\n') {
        if (images->buf[index] == ';')
            get_color(images, index + 1);
        index++;
    }
    return (0);
}

int get_header(image_g *images)
{
    int index = 0;

    while (images->buf[index] != '\0') {
        if (images->buf[index] == '2' && images->buf[index + 1] == '5' &&
        images->buf[index + 2] == '5' && images->buf[index + 3] == '\n') {
            my_putstr("255\n");
            return (index);
        }
        my_putchar(images->buf[index]);
        index++;
    }
    return (index);
}

int get_separators(image_g *images)
{
    images->index = get_header(images);
    images->index = images->index + 4;
    int index = images->index;

    while (images->buf[index] != '\0') {
        if (images->buf[index] == '\n')
            get_dictionary(images, index + 1);
        index++;
    }
    return (0);
}
