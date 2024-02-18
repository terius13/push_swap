/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:25:50 by ting              #+#    #+#             */
/*   Updated: 2024/02/18 21:19:38 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int	data;
	struct s_stack	*next;
}	t_stack;

//push_swap.c
void	print_stack(t_stack **stack_a);

//alloc_stacka.c
t_stack		*if_string(char *str);
t_stack		**allocate_stack_a(int count, char **argv);

//nodes_utils.c
t_stack	*new_node(int num);
void	add_node_bottom(t_stack **stack, t_stack *new);

//check_for_error.c
void	ft_error_msg(void);
int	check_for_digit(char **argv);
void	checker_argv(char **argv);

//swap_oper.c
void	swap(t_stack *stack);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b);

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

#endif
