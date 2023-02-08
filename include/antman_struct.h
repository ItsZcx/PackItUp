/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Write your my.h header file that contains the
** prototypes of all the functions exposed by your libmy.a
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct s_dictionary {
        char *ascii;
        char *color;
    } dictionary_t;

    typedef struct image_s{
        char *buf;
        char *compressed;
        char *path;
        char *prev_num;
        int num_lines;
        int num_count;
        int ascii;
        int ascii_1;
        int index_ascii;
        int dictionary_length;
        int bsn;
        int index;
        dictionary_t **dictionary;
    } image_t;

    typedef struct Link_list_img {
        char *color;
        int mult;
        char *ascii;
        char *temp_color;
        struct Link_list_img* next;
        struct Link_list_img* head;
    }Link_list_img;

    typedef struct s_content {
        char op;
        int(*ptr)(char *);
    } content_t;

    typedef struct l_txtnode {
        int order;
        char *word;
        char ascii;
        struct l_txtnode *next;
        struct l_txtnode *previus;
    } s_txtnode;

    typedef struct l_txtinfo {
        int cut;
        int index;
        int index2;
        int repeat;
        int ascii;
    } s_txtinfo;

#endif
