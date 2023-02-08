/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Write your my.h header file that contains the
** prototypes of all the functions exposed by your libmy.a
*/

#ifndef GIANTMAN_STRUCT_H_
    #define GIANTMAN_STRUCT_H_

    typedef struct dictionary_gm{
        char *color;
        char *ascii;
    } dictionary_g;

    typedef struct image_gm{
        int index;
        int setter;
        int rep_num;
        int num_lines;
        int color_mult;
        char *buf;
        char *path;
        char *prod;
        char *color;
        char *prev_num;
        char *compressed;
        dictionary_g **dictionary;
    } image_g;

    typedef struct text_gm{
        char *buf;
        char *compressed;
        char *path;
        char *color;
        int color_mult;
        char *prev_num;
        int num_lines;
        int rep_num;
        int index;
        int setter;
        dictionary_g **dictionary;
    } text_g;

    typedef struct gm_content {
        char op;
        int(*ptr)(char *);
    } content_g;

#endif
