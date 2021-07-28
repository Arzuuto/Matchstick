/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef _MY_H_
#define _MY_H_

#define TRUE (0)
#define EXIT (0)
#define FALSE (84)
#define EXIT_ERROR (84)

void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_printf(char *str, ...);
void my_put_strocta(char *str);
void my_put_hexa(int nb);
void my_puthexa_upper(int nb);
void my_put_address(long int nb);
void my_insigned_nbr(unsigned nb);
void my_put_octa(int nb);
void my_put_binary(int nb);
int my_compute_power_it(int nb, int p);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_atoi(char *str);
int main(int argc, char **argv);

int check_char(char c);
int check_number(char **av);
int get_line(char **map, int max_rows);
void free_game(char **game);
int check_buffer(char **map, char *str, int nb, int flags);
char **create_game(int nb);
int get_matches(char **map, int lines, int max);
char **update_map(char **map, int lines, int matches);
char *replace_sticks(char *str, int matches);
int start_game(int max_rows, int max_cols);
int find(char *str, char c);
int count(char *str, char c);
void print_array(char **array);
int get_number(char *nb);
char **create_tab(int rows, int cols);
char **ia_turn(char **map, int max_lines, int max_cols);
void free_game(char **game);
int player_turn(char **map, int max_rows, int max_cols);

#endif