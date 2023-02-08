/*
** EPITECH PROJECT, 2023
** B-CPE-110-BAR-1-1-antman-joan-pau.merida-ruiz
** File description:
** do_image
*/

#include "antman_lib.h"

int dictionary_setter(image_t *image, int contr, int index, int i)
{
    if (contr == 0) {
        if (image->index_ascii > 0)
                image->dictionary[index]->ascii[1] = image->ascii_1;
        if (image->index_ascii == 0 || image->index_ascii == 2)
            image->ascii++;
        else
            image->ascii_1++;
        image->dictionary[index]->ascii = my_strdup(
            image->dictionary[i]->ascii);
        image->dictionary[index]->color = my_strdup(image->prev_num);
        index++;
        image->dictionary_length++;
    }
    return (index);
}

int get_num(image_t *image, int index, int bsn)
{
    int len = my_strlen_mod(image->buf, index); int temp_index = 0;
    char *temp = malloc(sizeof(char) * (len + 1));

    while (image->buf[index] && image->buf[index] != '\n') {
        temp[temp_index] = image->buf[index];
        temp_index++; index++;
    }
    temp[temp_index] = '\0';
    if (bsn == image->bsn)
        image->prev_num = my_strdup(temp);
    if ((image->buf[index + 1] == '\0' || image->buf[index + 1] == '\n')
        && bsn >= 4 && my_strcmp(image->prev_num, temp) == 0
        && image->buf[index + 1] != '\0')
        image->num_count = image->num_count + 1;
    if (bsn >= image->bsn && my_strcmp(image->prev_num, temp) == 0
        && image->buf[index + 1] != '\0' && image->buf[index + 1] != '\n')
        image->num_count = image->num_count + 1;
    else
        print_num(image);
    image->prev_num = my_strdup(temp);
}

int do_compression(image_t *image)
{
    int bsn = 0;
    int index = 0;

    while (image->buf[index] != '\0') {
        if (bsn <= image->bsn && image->buf[index] == '\n')
            bsn++;
        if ((image->buf[index] == '\n'
            && bsn >= image->bsn) || (image->buf[index] == '\0'
            && bsn >= image->bsn))
            get_num(image, index + 1, bsn);
        index++;
    }
    if (image->buf[index] == '\0' && image->buf[index - 1] != '\n')
        get_num(image, index + 1, bsn);
}

int functions_group(image_t *image, int fd)
{
    image->ascii = 20;
    image->ascii_1 = 20;
    image->index_ascii = 0;

    close(fd);
    print_header(image);
    do_compression(image);
    my_putchar('\n');
    printing_dictionary(image);
}

int do_image(char *path)
{
    struct stat info;
    int a = stat(path, &info);

    if (a == -1)
        return (84);
    image_t *image = image_structs(path, info);
    image->dictionary = malloc(sizeof(content_t) * 256);
    if (image->dictionary == NULL)
        return (84);
    int fd = open(image->path, 0);
    if (fd == -1)
        return (84);
    int rd = read(fd, image->buf, info.st_size);
    if (rd == -1)
        return (84);
    image->buf[rd] = '\0';
    functions_group(image, fd);
}
