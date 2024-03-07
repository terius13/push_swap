/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:25:50 by ting              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/07 13:41:15 by ting             ###   ########.fr       */
=======
/*   Updated: 2024/03/07 11:27:19 by ting             ###   ########.fr       */
>>>>>>> dba8fc61a88de768f9a0c6a4062389104ed469c0
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
//might have to change/remove limits.h later on
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

/*
 * data : 6 2 3 7
 * pos  : 0 1 2 3
 * index: 3 1 2 4
target_pos: start from 0 too
*/

typedef struct s_stack
{
	struct s_stack	*next;
	long			data;
	long			pos;
	long			index;
	long			target_pos;
	int				cost_a;
	int				cost_b;
}	t_stack;

//push_swap.c
//main

//utils.c
int		find_smallest_num(t_stack *stack_a);
void	print_stack(t_stack **stack_a);
int		get_stack_size(t_stack *stack_a);
void	assign_pos(t_stack **stack_a);
void	assign_index(t_stack **stack_a);

//alloc_stacka.c
t_stack	*if_string(char *str);
t_stack	**allocate_stack_a(int count, char **argv);

//nodes_utils.c
t_stack	*new_node(int num);
void	add_node_bottom(t_stack **stack, t_stack *new);

//check_for_error.c
void	ft_error_msg(void);
void	check_for_digit(char **argv);
void	check_for_duplicates(char **argv);
void	checker_argv(char **argv);

//swap_oper.c
void	swap(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

//push_oper.c
void	push(t_stack **src, t_stack **dest);
void	push_a(t_stack **stack_b, t_stack **stack_a);
void	push_b(t_stack **stack_a, t_stack **stack_b);

//rotate_oper.c
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_a_and_b(t_stack **stack_b, t_stack **stack_a);

//re_rotate_oper.c
void	reverse_rotate(t_stack **stack);
void	re_rotate_a(t_stack **stack_a);
void	re_rotate_b(t_stack **stack_b);
void	re_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

//small_stack_algorithm.c
void	two_num_algor(t_stack **stack_a);
void	three_num_algor(t_stack **stack_a);
void	four_num_algor(t_stack **stack_a, t_stack **stack_b);
void	five_num_algor(t_stack **stack_a, t_stack **stack_b);

//big_stack_algorithm.c
void	big_stack_algor(t_stack **stack_a, t_stack **stack_b);
void	push_all_until_three_left(t_stack **stack_a, t_stack **stack_b);
void	assign_target_pos(t_stack **stack_a, t_stack **stack_b);

#endif
