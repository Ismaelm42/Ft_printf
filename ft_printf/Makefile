
NAME = libftprintf.a

SRC =	src/ft_printf.c

OBJT_DIR = .objt/

OBJT = $(addprefix $(OBJT_DIR), $(patsubst %.c, %.o, $(SRC)))

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(OBJT)
	$(AR) $(NAME) $(OBJT)

$(OBJT_DIR)%.o: %.c
	mkdir -p $(@D)
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
