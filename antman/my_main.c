/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** selector
*/

#include "antman_lib.h"

content_t content[3] = {
    {'1', &do_text},
    {'2', &do_image},
};

int do_selection(int ac, char **av)
{
    struct stat info;
    int a = stat(av[1], &info);

    if (a == -1)
        return (84);
    if (info.st_size == 0)
        return (0);
    for (int j = 0; j <= 3 && ac == 3; j++) {
        if (content[j].op == av[2][0])
            return (content[j].ptr(av[1]));
    }
}

int error_handle(int ac, char **av)
{
    struct stat info;
    int a = stat(av[1], &info);

    if (a == -1)
        return (84);
    if ((info.st_mode & S_IFMT != S_IFREG))
        return (84);
    if (ac != 3) {
        my_putstr("Error!\nYou are missing some argument!\n");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (help(ac, av) == 1)
        return (0);
    if (error_handle(ac, av) == 84)
        return (84);
    if (do_selection(ac, av) == 84)
        return (84);
    return (0);
}
