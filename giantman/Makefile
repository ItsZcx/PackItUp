##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME =	giantman

SRC =	my_main.c \
		help.c \
		text/init_text.c	\
		text/decompress_text.c	\
		text/get_dictionary_text.c	\
		images/init_images.c \
		images/get_dictionary.c \
		images/decompress_image.c

OBJ = $(SRC:.c=.o)

LIBMY = -C ../lib/c-lib

LIBR = -L ../lib/c-lib/ -lmy

CFLAGS += -I ../include/ -I ../lib/c-lib/include -g3

all: $(NAME)

$(NAME): make_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBR)
	rm -f *.o
	rm -f image/*.o
	rm -f text/*.o

make_lib:
	$(MAKE) $(LIBMY)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ../lib/c-lib/

test_run:
	gcc -o unit_tests unit_tests/soko_tests.c $(CFLAGS)
	rm -f *.gcda
	rm -f *.gcno
	./unit_tests
	rm -f ./unit_tests

re: fclean all
