/*
** EPITECH PROJECT, 2021
** test_units
** File description:
** test my functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void  redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(map, verify_buffer_with_number_5)
{
    char *test[] = {"***********", "*    |    *", "*   |||   *", "*  |||||  *" ,"* ||||||| *" ,"*|||||||||*" ,"***********"};
    char **map = create_game(5);

    for (int i = 0; i < 7; i += 1)
        cr_assert_str_eq(map[i], test[i]);
}

Test(utility_functions, find_stick_in_string)
{
    char with_sticks[] = "*|||||||||*";
    char without_sticks[] = "*         *";
    int test_with_sticks = find(with_sticks, '|');
    int test_without_sticks = find(without_sticks, '|');

    cr_assert_eq(test_with_sticks, 0);
    cr_assert_eq(test_without_sticks, 84);
}


Test(utility_functions, count_stick_in_string)
{
    char with_sticks[] = "*|||||||||*";
    char without_sticks[] = "*         *";
    int test_with_sticks = count(with_sticks, '|');
    int test_without_sticks = count(without_sticks, '|');

    cr_assert_eq(test_with_sticks, 9);
    cr_assert_eq(test_without_sticks, 0);
}

Test(game, check_player_turn, .init = redirect_all_std)
{
    char *map[] = {"***********", "*         *", "*         *", "*         *" ,"*         *" ,"*         *" ,"***********"};
    int test = player_turn(map, 5, 5);

    cr_assert_eq(test, 2);
    cr_assert_stdout_eq_str("I lost... snif... but I'll get you next time!!\n");
}

Test(change_map, remove_sticks)
{
    char str[] = "*|||||||||*";
    char *array;

    array = replace_sticks(str, 3);
    cr_assert_str_eq(array, "*||||||   *");
}