/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** check_argv
*/

#include <stdlib.h>
#include "my.h"

int check_char(char c)
{
    if ((c >= '0' && c <= '9') || c == '*')
        return (FALSE);
    return (TRUE);
}

int check_number(char **av)
{
    int i = 1;
    int j = 0;
    int error = 0;

    for (i = 1; av[i] != NULL; i++) {
        for (j = 0; av[i][j] != '\0';) {
            error = check_char(av[i][j]);
            if (error == TRUE)
                return (FALSE);
            j++;
        }
    }
    return (TRUE);
}

void free_game(char **game)
{
    for (int i = 0; game[i] != NULL; i++)
        free(game[i]);
    free(game);
}