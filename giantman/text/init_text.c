/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** init_images
*/

#include "giantman_lib.h"

int init_text(char *path)
{
    text_g *text = malloc(sizeof(text_g));
    text->path = malloc(sizeof(char) * (my_strlen(path) + 1));
    my_strcpy(text->path, path);
    get_buffer_text(text);
    return (0);
}

int get_buffer_text(text_g *text)
{
    struct stat sb;
    stat(text->path, &sb);
    text->buf = malloc(sizeof(char) *(sb.st_size + 1));
    int fd = open(text->path, 0);
    int rd = read(fd, text->buf, sb.st_size);
    text->buf[rd] = '\0';
    get_separators_text(text);
    return (0);
}
