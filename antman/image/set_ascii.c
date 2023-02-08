/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** set_ascii
*/

#include "antman_lib.h"

int set_ascii_char(image_t *image)
{
    if (image->ascii == 255) {
        image->ascii = 32;
        image->index_ascii++;
    }
    if (image->ascii_1 == 255) {
        image->ascii_1 = 32;
        image->ascii++;
        image->index_ascii++;
    }
    if (image->ascii == 59)
        image->ascii++;
    if (image->ascii_1 == 59)
        image->ascii_1++;
    if (image->ascii == 120)
        image->ascii++;
    if (image->ascii_1 == 120)
        image->ascii_1++;
}

int set_ascii(image_t *image, char *color)
{
    set_ascii_char(image);
    int i = 0;
    int contr = 0;
    static int index = 0;
    image->dictionary[index] = malloc(sizeof(content_t));
    image->dictionary[index]->ascii = malloc(sizeof(char) * 4);
    image->dictionary[index]->ascii[0] = image->ascii;

    while (i < index && contr == 0) {
        if (my_strcmp(image->prev_num, image->dictionary[i]->color) == 0) {
            contr++;
            return (i + 1);
        }
        i++;
    }
    index = dictionary_setter(image, contr, index, i);
    return (index);
}
