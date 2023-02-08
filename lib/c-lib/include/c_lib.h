/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-myls-joan-pau.merida-ruiz
** File description:
** prototypes
*/

#ifndef C_LIB_H
    #define C_LIB_H

    #include <stdlib.h>

    void my_putchar(char c);
    void my_putstr(char *str);
    int	my_get_nbr(char *str);
    int my_put_nbr(int x);
    int my_strlen(char *str);
    int my_strcmp(char *str_1, char *str_2);
    char **my_str_to_word_array(char *str, char separator);
    char *my_strcpy(char *dest, char const *src);
    int my_strlen_mod(char *str, int index);
    int my_bsn_count(char *str);
    char *my_strdup(char *src);
    int my_dict_length(char * str , int index);
    int my_ascii_length(char * str , int index);
    int my_cut(char *str, char *sub_str);

#endif
