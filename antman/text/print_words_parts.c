/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** print_words_parts
*/

#include "antman_lib.h"

void print_end_word(int cut, int strlen_arr_i, char *arr_i)
{
    while (cut < strlen_arr_i) {
        my_putchar(arr_i[cut]);
        cut++;
    }
}

void print_start_word(int cut, char *arr_i)
{
    int index = 0;

    while (index < cut) {
        my_putchar(arr_i[index]);
        index++;
    }
}

void print_end_word_condition(int cut, int strlen_arr_i,
char *arr_i, s_txtnode *temp)
{
    if (cut < strlen_arr_i)
        print_end_word(cut + my_strlen(temp->word),
            strlen_arr_i, arr_i);
}
