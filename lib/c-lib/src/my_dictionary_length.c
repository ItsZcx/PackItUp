/*
** EPITECH PROJECT, 2022
** task03
** File description:
** Function that counts and returns the number of characters in a string.
*/

#include <unistd.h>

int my_dict_length(char * str , int index)
{
    int count = 0;

    while (str[index] && str[index] != '_' && str[index] != ';'
    && str[index] && str[index] != 'x' && str[index] != '/'){
        index ++;
        count++;
    }
    return (count);
}

int my_ascii_length(char * str , int index)
{
    int count = 0;

    while (str[index] && str[index] != '/' && str[index] != '\0') {
        index ++;
        count++;
    }
    return (count);
}
