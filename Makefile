# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 11:09:54 by ting              #+#    #+#              #
#    Updated: 2024/02/15 15:34:12 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

SRC = src/alloc_stacka.c src/checker.c \
      src/error_msg.c src/push_swap.c \

OBJ = $(SRC:.c=.o)

all: $(LIBFT_SRC) $(NAME) 

$(LIBFT_SRC):
	$(MAKE) -C libft

$(NAME):
	cc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(LIBFT)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)
