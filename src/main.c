/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int main(int argc, char **argv)
{
    if (argc != 3 || check_number(argv) == FALSE)
        return (EXIT_ERROR);
    return (start_game(get_number(argv[1]), get_number(argv[2])));
}