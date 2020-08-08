NAME=printf.a
CC=clang
CFLAGS=-Werror -Wall -Wextra
SRC=*.c
OBJ=*.o

all: $(NAME)

$(NAME):
	@$(CC) $(SRC) $(CFLAGS) -c
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: clean all