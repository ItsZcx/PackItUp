/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** do_text
*/

#include "antman_lib.h"

void skip_semicolom(s_txtinfo *info)
{
    if (info->ascii == 58)
        info->ascii++;
}

s_txtnode *fill_hardcoded_list(s_txtnode *node, s_txtinfo *info)
{
    node = create_head_node(node, "tion", my_strlen("tion"));
    char *hard_coded_words[] = {"ound", "ough", "ment", "ness", "once", "mis",
    "ive", "ate", "ise", "ing", "ght", "ver", "ace"};

    for (int loop = 0; loop < 12; loop++) {
        node = create_nodes(node, hard_coded_words[loop], 0, info->ascii);
        info->ascii++;
    }
    return (node);
}

s_txtnode *fill_linked_list_condition(char **arr,
s_txtinfo *info, s_txtnode *node)
{
    while (arr[info->index2]) {
        if (info->repeat != 1 && info->index != info->index2
            && my_strcmp(arr[info->index], arr[info->index2]) == 0
            && already_in_list(node, arr[info->index2]) == false) {
            node = create_nodes(node, arr[info->index],
                my_strlen(arr[info->index]), info->ascii);
            node->order = 2;
            info->repeat = 1;
            skip_semicolom(info);
            info->ascii++;
        }
        info->repeat = 0;
        info->index2++;
    }
    return (node);
}

void fill_linked_list(char **arr)
{
    s_txtinfo *info = init_txt_info();
    s_txtnode *node = init_structs();

    node = fill_hardcoded_list(node, info);
    while (arr[info->index] && info->ascii != 128) {
        if (my_strlen(arr[info->index]) >= 3) {
            node = fill_linked_list_condition(arr, info, node);
            info->index2 = 0;
        }
        info->index++;
    }
    print_everything(node, arr, info);
}

int do_text(char *path)
{
    struct stat info;
    int a = stat(path, &info);

    if (a == -1)
        return (84);
    char *song = malloc(sizeof(char) * (info.st_size + 1));
    if (song == NULL)
        return (84);
    int fd = open(path, 0);
    if (fd == -1)
        return (84);
    int rd = read(fd, song, info.st_size);
    if (rd == -1)
        return (84);
    song[rd] = '\0';
    char **arr = my_str_to_word_array(song, ' ');
    fill_linked_list(arr);
    close (fd);
}
