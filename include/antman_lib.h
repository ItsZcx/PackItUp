/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-myls-joan-pau.merida-ruiz
** File description:
** prototypes
*/

#ifndef LIB_H_
    #define LIB_H_

    #include "c_lib.h"
    #include "antman_struct.h"
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdbool.h>

    int do_text(char *path);
    int do_image(char *path);
    int print_num(image_t *image);
    int selector(int ac, char **av);
    int print_header(image_t *image);
    int do_compression(image_t *image);
    int get_buffer_image(image_t *image);
    int get_buffer_image(image_t *image);
    int printing_dictionary(image_t *image);
    int set_ascii(image_t *image, char *color);
    int already_in_list_2(s_txtnode *node, char *arr_i);
    int dictionary_setter(image_t *image, int contr, int index, int i);
    void print_ascii(s_txtnode *node, char *str);
    void print_start_word(int cut, char *arr_i);
    void print_everything(s_txtnode *node, char **arr, s_txtinfo *info);
    void print_end_word_condition(int cut, int strlen_arr_i,
        char *arr_i, s_txtnode *temp);
    char *my_strcpy(char *dest, char const *src);
    bool already_in_list(s_txtnode *node, char *str);
    image_t *image_structs(char *path, struct stat info);
    s_txtnode *init_structs(void);
    s_txtinfo *init_txt_info(void);
    s_txtnode *to_last_node(s_txtnode *node);
    s_txtnode *print_dictionary(s_txtnode *node);
    s_txtnode *create_head_node(s_txtnode *node, char *word, int len);
    s_txtnode *create_nodes(s_txtnode *last, char *word, int len, int ascii);
    int help(int ac, char **av);

#endif
