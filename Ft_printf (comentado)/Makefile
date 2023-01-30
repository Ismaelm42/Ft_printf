# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:09:39 by imoro-sa          #+#    #+#              #
#    Updated: 2023/01/23 11:27:47 by imoro-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_PATH = ./Libft/

LIBFT = Libft

LIBFT.A = libft.a

SRC = ft_printf.c ft_call.c ft_char.c ft_string.c ft_pointer.c ft_decimal.c \
	ft_integer.c ft_unsigned.c ft_lower_case_hex.c ft_cap_hex.c

OBJT = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

COLOUR_END = \033[0m
COLOUR = \033[0;96m

all: $(NAME)

$(NAME): $(OBJT) $(LIBFT.A)
	@cp $(LIBFT_PATH)$(LIBFT.A) .
	@mv $(LIBFT.A) $(NAME)
	@gcc $(CFLAGS) -c $(SRC)
	@ $(AR) $(NAME) $(OBJT)
	@echo "$(COLOUR)libft included in libftprintf.a and printf functions compiled!$(COLOUR_END)"

$(LIBFT.A):
	@make -C $(LIBFT)
	@echo "$(COLOUR)libft functions compiled!$(COLOUR_END)"

clean:
	@ $(RM) $(OBJT)
	@make clean -C $(LIBFT)
	@echo "$(COLOUR)*.o cleaned!$(COLOUR_END)"

fclean: clean
	@ $(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(COLOUR)*.o and *.a cleaned!$(COLOUR_END)"

re: fclean all
	@echo "$(COLOUR)all cleaned and rebuilt!$(COLOUR_END)"

.PHONY: all clean fclean bonus re