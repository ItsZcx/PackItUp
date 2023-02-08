/*
** EPITECH PROJECT, 2022
** task03
** File description:
** Function that counts and returns the number of characters in a string.
*/

#include <unistd.h>

int my_strlen_mod(char * str , int index)
{
    int count = 0;

    while (str[index] && str[index] != '\n' && str[index] != '\0'){
        index ++;
        count++;
    }
    return (count);
}
