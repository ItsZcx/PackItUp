/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** main
*/

#include "giantman_lib.h"

content_g content[3] = {
    {'1', &init_text},
    {'2', &init_images},
};

int selector(char **av)
{
    for (int j = 0; j < 3; j++) {
        if (content[j].op == av[2][0])
            return (content[j].ptr(av[1]));
    }
    return (0);
}

int error_handle(int ac, char **av)
{
    struct stat info;
    int a = stat(av[1], &info);

    if (ac != 3)
        return (84);
    if (a == -1)
        return (84);
    if ((info.st_mode & S_IFMT) != S_IFREG)
        return (84);
    return (0);
}

int do_empty_file(int ac, char **av)
{
    struct stat sb;
    int a = stat(av[1], &sb);

    if (a == -1)
        return (84);
    if (sb.st_size == 0)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    if (help(ac, av) == 1)
        return (0);
    if (error_handle(ac, av) == 84)
        return (84);
    if (do_empty_file(ac, av) != 1)
        return (do_empty_file(ac, av));
    if (selector(av) == 84)
        return (84);
    return (0);
}
