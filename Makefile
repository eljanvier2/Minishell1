##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task 01
##

SRC_MAIN =	./src/main_file.c

SRC	=	./src/str_utils/my_putstr.c	\
		./src/str_utils/my_strcmp.c	\
		./src/str_utils/my_strncmp.c	\
		./src/str_utils/my_strtoword.c	\
		./src/str_utils/str_handling.c	\
		./src/str_utils/my_strncat.c	\
		./src/str_utils/my_strlen.c	\
		./src/operating_utils/init_file.c	\
		./src/operating_utils/prompt.c	\
		./src/operating_utils/run.c	\
		./src/env_utils/env_ops.c	\
		./src/env_utils/env_ops2.c	\
		./src/env_utils/path_ops.c	\
		./src/commands/cd_utils.c	\
		./src/commands/pwd_ops.c	\
		./src/commands/my_execve.c

NAME 	=	mysh

CPPFLAGS =	-I./include
CFLAGS =	-W -Wall -Wextra

LDFLAGS =

TESTS_FLAGS = --coverage -lcriterion
TESTS_FLAGS += -I./include

TESTS_SRC =	./tests/lenght_tests.c	\
			./tests/my_put_nbr.c	\
			./tests/tests_str.c

OBJ =	$(SRC:.c=.o)
OBJ_GCDA =	$(SRC:.c=.gcda)
OBJ_GCNO =	$(SRC:.c=.gcno)
OBJ_MAIN =	$(SRC_MAIN:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN)

debug:	CFLAGS += -g
debug:	fclean $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_MAIN) $(OBJ_TEST) $(OBJ_GCDA) $(OBJ_GCNO)
	rm -rf unit*
	rm -rf vgcore*

fclean: clean
	rm -rf $(NAME)

re:	fclean all

tests_run: CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run:	fclean $(OBJ) $(OBJ_TEST)
	rm -rf unit*
	gcc -o unit_tests $(OBJ) $(OBJ_TEST) $(LDFLAGS) $(CFLAGS)
	./unit_tests
	gcovr

cover:
	mkdir -p crit_result
	gcovr --exclude tests/ --html --html-details -o crit_result/cov.html
	gcovr --branches --exclude tests/

auteur:
	echo $(USER) > auteur

.PHONY:	all clean fclean re auteur debug tests_run cover
