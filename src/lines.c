/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** lines.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int check_line(char **map, char *str, int max)
{
    int i = 0;
    int nb = get_number(str);

    for (i = 0; str[i] != '\0';)
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n')
            i++;
        else {
            my_printf("Error: invalid input (positive number expected)\n");
            return (FALSE);
        }
    if (nb > max || find(map[nb], '|') == FALSE) {
        my_printf("this line is out of range\n");
        return (FALSE);
    }
    return (TRUE);
}

int get_line(char **map, int max_rows)
{
    char *buffer = NULL;
    ssize_t len = 0;
    size_t n = 0;
    int nb = 0;

    while (1) {
        my_printf("Line: ");
        len = getline(&buffer, &n, stdin);
        if (len == -1 || buffer == NULL || buffer[0] == '\n')
            return (-1);
        if (check_line(map, buffer, max_rows) == TRUE)
            break;
    }
    nb = get_number(buffer);
    free(buffer);
    return (nb);
}
