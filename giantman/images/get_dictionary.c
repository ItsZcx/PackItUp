/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** get_dictionary
*/

#include "giantman_lib.h"

int get_dictionary_malloc(image_g *images, int position)
{
    int count = 0;
    int index = 0;

    while (images->buf[position] != '\0') {
        if (images->buf[position] == ';')
            count++;
        position++;
    }
    images->dictionary = malloc(sizeof(dictionary_g) *(count + 1));
    while (index < count) {
        images->dictionary[index] = malloc(sizeof(dictionary_g));
        index++;
    }
    return (0);
}

int get_dictionary_number(image_g *images, int position, int num)
{
    int index = 0;

    while (images->buf[position] != '_') {
        images->dictionary[num]->color[index] = images->buf[position];
        position++;
        index++;
    }
    images->dictionary[num]->color[index] = '\0';
    index = 0;
    position = position + 1;
    while (images->buf[position] != ';' && images->buf[position] != '\0') {
        images->dictionary[num]->ascii[index] = images->buf[position];
        position++;
        index++;
    }
    images->dictionary[num]->ascii[index] = '\0';
    return (0);
}

int get_dictionary(image_g *images, int position)
{
    int count = 0;
    int len;

    get_dictionary_malloc(images, position);
    while (images->buf[position] != '\0') {
        if (images->buf[position] == ';') {
            len = my_dict_length(images->buf, position + 1);
            images->dictionary[count]->color = malloc(sizeof(char *) * (len));
            images->dictionary[count]->ascii = malloc(sizeof(char *) * (4));
            get_dictionary_number(images, position + 1, count);
            count++;
        }
        position++;
    }
    images->dictionary[count] = NULL;
    get_descompressor(images);
    return (0);
}
