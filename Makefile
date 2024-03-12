# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 11:09:54 by ting              #+#    #+#              #
#    Updated: 2024/03/12 15:18:56 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

SRC_PATH = src/

SRC = alloc_stacka.c push_swap.c \
      check_for_error.c nodes_utils.c \
      swap_oper.c push_oper.c \
      rotate_oper.c re_rotate_oper.c \
      small_stack_algorithm.c utils.c \
      big_stack_algorithm.c calculate_cost.c \
      big_stack_algor_oper.c

OBJ = $(addprefix $(SRC_PATH), $(SRC:.c=.o))

#OBJS_RM = $(SRC:.c=.o)

all: $(LIBFT) $(NAME) 

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re: fclean all
