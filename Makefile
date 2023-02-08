##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

LIBMY = -C lib/c-lib

ANTMAN = -C antman/

GIANTMAN = -C giantman/

LIBR = -L lib/c-lib/ -lmy

CFLAGS += -I ./include/ -I ./lib/c-lib/include -g3

all: make_dirs

make_dirs:
	$(MAKE) $(ANTMAN)
	$(MAKE) $(GIANTMAN)

clean:
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./antman/
	make fclean -C ./giantman/

test_run:
	gcc -o unit_tests unit_tests/soko_tests.c $(CFLAGS)
	rm -f *.gcda
	rm -f *.gcno
	./unit_tests
	rm -f ./unit_tests

re: fclean all
