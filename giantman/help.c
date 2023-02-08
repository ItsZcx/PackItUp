/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-giantman-joan-pau.merida-ruiz
** File description:
** help
*/

#include "giantman_lib.h"

int help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("USAGE\n");
        my_putstr("    ./giantman [path_file] [type_file]\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("    path_file: path of the file that you want to decompress.\n");
        my_putstr("    type_file: number representing the fyle type.\n");
        my_putstr("        1: text (capable of decompressing emojis).\n");
        my_putstr("        2: P3 PPM images.\n\n");
        my_putstr("TIP\n");
        my_putstr("    Use './@man [path_file] [type] > [name_file]'\n");
        my_putstr("    That way you can store the compressed or decompressed file in a newly created file, [name_file].\n");
        my_putstr("    You can also use the command 'diff [path_giantman_decompressed_file] [path_original_file]', to compare files.\n");
        my_putstr("    If nothing shows up, that means that the files are identical.\n");
        return (1);
    }
    return (0);
}