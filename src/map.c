/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** map
*/

#include <stdlib.h>
#include "my.h"

static char **fill_side(char **game, int rows, int cols)
{
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols; j++)
            game[i][j] = ' ';
        game[i][0] = '*';
        game[i][cols - 1] = '*';
        game[i][cols] = '\0';
    }
    return (game);
}

static char **fill_limiter(char **game, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        if (i == 0 || i == rows - 1)
            for (int j = 0; j < cols; j++)
                game[i][j] = '*';
    return (game);
}

static char **fill_stick(char **game, int rows, int cols)
{
    for (int i = rows - 2; i > 0; i--)
        for (int j = 1; j < cols - 1; j++)
            game[i][j] = '|';
    return (game);
}

static char **fill_space(char **game, int cols, int nb)
{
    int j = 1;
    int space = nb;

    for (int i = 1; i < cols - 1; i++) {
        for (j = 1; j < space; j++)
            game[i][j] = ' ';
        space--;
    }
    j = nb + 1;
    for (int i = 1; i < cols - 1; i++) {
        while (j < cols - 1) {
            game[i][j] = ' ';
            j++;
        }
        j = nb + (i + 1);
    }
    return (game);
}

char **create_game(int nb)
{
    int cols = 1 + (2 * nb);
    int lines = 2 + nb;
    char **map = create_tab(lines, cols);

    if (map == NULL)
        return (NULL);
    map = fill_limiter(map, lines, cols);
    map = fill_side(map, lines, cols);
    map = fill_stick(map, lines, cols);
    map = fill_space(map, cols, nb);
    return (map);
}
