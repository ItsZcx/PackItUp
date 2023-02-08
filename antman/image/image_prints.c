/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** image_prints
*/

#include "antman_lib.h"

int print_num(image_t *image)
{
    int index = set_ascii(image, image->prev_num);

    my_putchar(';');
    if (image->num_count < 2)
        my_putstr(image->dictionary[index - 1]->ascii);
    else {
        my_putstr(image->dictionary[index - 1]->ascii);
        my_putchar('x');
        my_put_nbr(image->num_count);
    }
    image->num_count = 1;
}

int print_header(image_t *image)
{
    int index = 0;
    image->bsn = 0;
    char *temp = malloc(sizeof(char) * 5);

    while (image->buf[index]) {
        if (image->buf[index] == '\n')
            image->bsn++;
        if (image->buf[index] == '2' && image->buf[index + 1] == '5'
            && image->buf[index + 2] == '5' && image->buf[index + 3] == '\n') {
            my_putstr("255\n");
            image->bsn++;
            return (0);
        }
        my_putchar(image->buf[index]);
        index++;
    }
}

int printing_dictionary(image_t *image)
{
    int i = 0;

    while (i < image->dictionary_length - 1) {
        my_putchar(';');
        my_putstr(image->dictionary[i]->color);
        my_putchar('_');
        my_putstr(image->dictionary[i]->ascii);
        i++;
    }
    if (image->dictionary[i]) {
        my_putchar(';');
        my_putstr(image->dictionary[i]->color);
        my_putchar('_');
        my_putstr(image->dictionary[i]->ascii);
    }
}
