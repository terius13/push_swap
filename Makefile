# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 11:09:54 by ting              #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2024/02/28 19:39:22 by ting             ###   ########.fr        #
=======
#    Updated: 2024/02/29 13:08:44 by ting             ###   ########.fr        #
>>>>>>> b06f84b06baa5f3f99e8dc41c6036331fc7619de
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


OBJ = $(addprefix $(SRC_PATH), $(SRC:.c=.o))

OBJS_RM = $(SRC:.c=.o)

all: $(LIBFT) $(NAME) 

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(LIBFT_SRC) $(OBJ)
	cc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re: fclean all
