##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME =	antman

SRC =	my_main.c \
		help.c \
		image/do_image.c \
		image/image_structs.c \
		image/set_ascii.c \
		image/image_prints.c \
		text/do_text.c \
		text/text_nodes.c \
		text/text_prints.c \
		text/text_prints2.c \
		text/init_text_info.c \
		text/print_words_parts.c

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
