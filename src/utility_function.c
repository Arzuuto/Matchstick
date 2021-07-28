/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** utility_function.c
*/

#include <stdlib.h>
#include "my.h"

int find(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (TRUE);
    return (FALSE);
}

int count(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count += 1;
    return (count);
}

void print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_printf("%s\n", array[i]);
    }
    my_printf("\n");
}

int get_number(char *nb)
{
    if (my_strlen(nb) == 1) {
        return (nb[0] - 48);
    } else {
        return (my_atoi(nb));
    }
}

char **create_tab(int rows, int cols)
{
    char **map = malloc(sizeof(char *) * (rows + 1));
    int i = 0;

    if (map == NULL)
        return (NULL);
    for (i = 0; i < rows; i++) {
        map[i] = malloc(sizeof(char) * cols + 1);
        map[i][cols] = '\0';
        if (map[i] == NULL)
            return (NULL);
    }
    map[i] = NULL;
    return (map);
}
