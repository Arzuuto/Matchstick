/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include "my.h"

static int check_end(char **map, int max_rows)
{
    int end = 0;

    for (int i = 0; i < max_rows; i++)
        if (find(map[i + 1], '|') == FALSE)
            end++;
    if (end == max_rows)
        return (TRUE);
    return (FALSE);
}

int get_turn(char **map, int max_rows, int max_cols)
{
    int lines;
    int matches;

    while (1) {
        lines = get_line(map, max_rows);
        if (lines == -1) {
            free_game(map);
            return (-1);
        }
        if ((matches = get_matches(map, lines, max_cols)) > 0)
            break;
        if (matches == -1) {
            free_game(map);
            return (-1);
        }
    }
    my_printf("Player removed %d match(es) from line %d\n", matches, lines);
    map = update_map(map, lines, matches);
    return (0);
}

int player_turn(char **map, int max_rows, int max_cols)
{
    int check;

    if (check_end(map, max_rows) == TRUE) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (2);
    }
    my_printf("Your turn:\n");
    check = get_turn(map, max_rows, max_cols);
    if (check == -1)
        return (-1);
    return (0);
}

int game_loop(char **map, int max_rows, int max_cols)
{
    int res;

    res = player_turn(map, max_rows, max_cols);
    if (res != 0)
        return (res);
    if (check_end(map, max_rows) == TRUE) {
        my_printf("You lost, too bad...\n");
        return (1);
    }
    map = ia_turn(map, max_rows, max_cols);
    return (0);
}

int start_game(int max_rows, int max_cols)
{
    char **map = create_game(max_rows);
    int res;

    if (map == NULL)
        return (EXIT_ERROR);
    print_array(map);
    while (1) {
        res = game_loop(map, max_rows, max_cols);
        if (res != 0)
            break;
    }
    if (res == -1)
        return (0);
    return (res);
}
