/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** giantman_lib
*/

#ifndef GIANTMANLIB_H_
    #define GIANTMANLIB_H_

    #include "c_lib.h"
    #include "giantman_struct.h"
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>

    int get_buffer_image(image_g *image, struct stat sb);
    int init_images(char *path);
    int get_separators(image_g *image);
    int get_dictionary(image_g *images, int position);
    int get_descompressor(image_g *images);
    int get_dictionary_text(text_g *images, int position);
    int init_text(char *path);
    int get_separators_text(text_g *images);
    int get_descompressor_text(text_g *images);
    int get_buffer_text(text_g *image);
    int help(int ac, char **av);

#endif
