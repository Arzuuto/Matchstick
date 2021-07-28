/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matches
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int check_map(char **map, int nb, int lines)
{
    if (nb == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (FALSE);
    }
    if (count(map[lines], '|') < nb) {
        my_printf("Error: not enough matches on this line\n");
        return (FALSE);
    }
    return (TRUE);
}

static int check_matches(char **map, char *str, int max, int lines)
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
    if (nb > max) {
        my_printf("Error: you cannot remove more than ");
        my_printf("%d matches per turn\n", max);
        return (FALSE);
    }
    if (check_map(map, nb, lines) == FALSE)
        return (FALSE);
    return (TRUE);
}

int get_matches(char **map, int lines, int max)
{
    char *buffer = NULL;
    ssize_t len = 0;
    size_t n = 0;
    int nb = 0;

    while (1) {
        my_printf("Matches: ");
        len = getline(&buffer, &n, stdin);
        if (len == -1 || buffer == NULL || buffer[0] == '\n')
            return (-1);
        if (check_matches(map, buffer, max, lines) == TRUE)
            break;
        else
            return (-2);
    }
    nb = get_number(buffer);
    free(buffer);
    return (nb);
}

char *replace_sticks(char *str, int matches)
{
    int count = 0;
    int len = my_strlen(str);

    for (int i = len; i > 0; i--)
        if (str[i] == '|') {
            if (count < matches)
                str[i] = ' ';
            count++;
        }
    return (str);
}