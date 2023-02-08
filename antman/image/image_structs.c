/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-myls-joan-pau.merida-ruiz
** File description:
** init_structs
*/

#include "antman_lib.h"

image_t *image_structs(char *path, struct stat info)
{
    image_t *image = malloc(sizeof(image_t));

    image->num_lines = 0;
    image->num_count = 0;
    image->buf = malloc(sizeof(char) * (info.st_size + 1));
    image->path = malloc(sizeof(char) * (my_strlen(path) + 1));
    my_strcpy(image->path, path);
    return (image);
}
