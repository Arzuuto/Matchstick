##
## EPITECH PROJECT, 2021
## my_defender
## File description:
## Makefile
##

SRC		=	./src/map.c	\
			./src/lines.c	\
			./src/utility_function.c	\
			./src/check_argv.c	\
			./src/matchstick.c	\
			./src/matches.c	\
			./src/computer.c

OBJ		=	$(SRC:.c=.o)

NAME		=	matchstick

TEST_NAME	=	test_units

CPPFLAGS	= -I include/

CFLAGS	=	-Wall -Wextra -Werror  -g3 -O3

LDFLAGS	=	-L lib/my -l my

CRITERION = -lcriterion --coverage

all:	$(NAME)

$(NAME): $(OBJ)
	cd lib/my && $(MAKE)
	gcc -o $(NAME) $(OBJ) src/main.c $(LIB) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

tests_run:
	gcc -o $(TEST_NAME) $(SRC) tests/test_matchstick.c $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) $(CRITERION)
	-./$(TEST_NAME)

clean:
	rm -f $(OBJ)
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f *~
	rm -f *.html

fclean: clean
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a
	rm -f *.gcda
	rm -f *.gcno

re:	fclean all tests_run

.PHONY: all clean fclean re tests_run
