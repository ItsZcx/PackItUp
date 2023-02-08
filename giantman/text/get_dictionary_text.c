/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** get_dictionary
*/

#include "giantman_lib.h"

int get_dictionary_malloc_text(text_g *text, int position)
{
    int index = 0;
    int count = 0;

    while (text->buf[position] != '\0') {
        if (text->buf[position] == ';')
            count++;
        position++;
    }
    text->dictionary = malloc(sizeof(dictionary_g) * (count + 1));
    while (index < count) {
        text->dictionary[index] = malloc(sizeof(dictionary_g));
        index++;
    }
    return (0);
}

int get_dictionary_number_text(text_g *text, int position, int num)
{
    int index = 0;

    while (text->buf[position] != '_') {
        text->dictionary[num]->color[index] = text->buf[position];
        position++;
        index++;
    }
    text->dictionary[num]->color[index] = '\0';
    index = 0;
    position = position + 1;
    while (text->buf[position] != ';' && text->buf[position] != '\0') {
        text->dictionary[num]->ascii[index] = text->buf[position];
        position++;
        index++;
    }
    text->dictionary[num]->ascii[index] = '\0';
    return (0);
}

int get_dictionary_text(text_g *text, int position)
{
    int count = 0;
    int len;

    get_dictionary_malloc_text(text, position);
    while (text->buf[position] != '\0') {
        if (text->buf[position] == ';') {
            len = my_dict_length(text->buf, position + 1);
            text->dictionary[count]->color = malloc(sizeof(char *) * (len));
            text->dictionary[count]->ascii = malloc(sizeof(char *) * (2));
            get_dictionary_number_text(text, position + 1, count);
            count++;
        }
        position++;
    }
    text->dictionary[count] = NULL;
    get_descompressor_text(text);
    return (0);
}
