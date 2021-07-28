/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** computer.c
*/

#include "stdlib.h"
#include "my.h"
#include <time.h>

char **update_map(char **map, int lines, int matches)
{
    map[lines] = replace_sticks(map[lines], matches);
    print_array(map);
    return (map);
}

static int check_rand_lines(char **map, int lines)
{
    if (find(map[lines], '|') == FALSE)
        return (FALSE);
    return (TRUE);
}

static int check_rand_cols(char **map, int lines, int matches)
{
    if (count(map[lines], '|') < matches || matches == 0)
        return (FALSE);
    return (TRUE);
}

char **ia_turn(char **map, int max_lines, int max_cols)
{
    int lines;
    int matches;

    srand(time(0));
    lines = random() % max_lines + 1;
    matches = 1;
    my_printf("AI's turn...\n");
    while (check_rand_lines(map ,lines) != TRUE)
        lines = random() % max_lines;
    while (check_rand_cols(map, lines,matches) != TRUE)
        matches = random() % max_cols;
    my_printf("AI removed %d match(es) from line %d\n", matches, lines);
    map = update_map(map, lines, matches);
    return (map);
}
