/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** Write a function that copies a string into another.
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
