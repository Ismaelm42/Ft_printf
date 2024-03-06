NAME = libftprintf

SRC = ft_printf.c

OBJT = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:  $(NAME)

$(NAME): $(OBJT)
	${CC} $(CFLAGS) $(SRC) -o ${NAME}

clean:
	$(RM) $(OBJT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
