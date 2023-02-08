/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** init_images
*/

#include "giantman_lib.h"

int init_images(char *path)
{
    image_g *image = malloc(sizeof(image_g));
    struct stat sb;
    if (image == NULL)
        return (84);
    int a = stat(path, &sb);
    if (a == -1)
        return (84);
    if (sb.st_size == 0)
        return (0);
    image->path = my_strdup(path);
    if (get_buffer_image(image, sb) == 84)
        return (84);
    return (0);
}

int get_buffer_image(image_g *image, struct stat sb)
{
    image->buf = malloc(sizeof(char) * (sb.st_size + 1));
    if (image->buf == NULL)
        return (84);
    int fd = open(image->path, 0);
    if (fd == -1)
        return (84);
    int rd = read(fd, image->buf, sb.st_size);
    if (rd == -1)
        return (84);
    image->buf[rd] = '\0';
    get_separators(image);
    return (0);
}
