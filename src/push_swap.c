/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:01 by ting              #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/03/17 14:28:14 by ting             ###   ########.fr       */
=======
/*   Updated: 2024/03/13 11:55:19 by ting             ###   ########.fr       */
>>>>>>> parent of bb5fd04 (mem errors)
=======
/*   Updated: 2024/03/13 11:55:19 by ting             ###   ########.fr       */
>>>>>>> parent of bb5fd04 (mem errors)
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

<<<<<<< HEAD
//	tmp = *stack;
	if (!*stack)
=======
	tmp = *stack;
	if (!stack || !*stack)
<<<<<<< HEAD
>>>>>>> parent of bb5fd04 (mem errors)
=======
>>>>>>> parent of bb5fd04 (mem errors)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
<<<<<<< HEAD
<<<<<<< HEAD
		printf("yyyyyyyyy %p %p\n", *stack, tmp);
		(*stack)->data = 0;
		(*stack)->pos = 0;
		(*stack)->index = 0;
		(*stack)->target_pos = 0;
		(*stack)->cost_a = 0;
		(*stack)->cost_b = 0;
		free (*stack);
//		*stack = NULL;
		*stack = tmp;
	}
	free (stack);
//	stack = NULL;
=======
		(*stack)->
		free (*stack);
		*stack = tmp;
	}
	*stack = NULL;
>>>>>>> parent of bb5fd04 (mem errors)
=======
		(*stack)->
		free (*stack);
		*stack = tmp;
	}
	*stack = NULL;
>>>>>>> parent of bb5fd04 (mem errors)
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;
	int	stack_size;

<<<<<<< HEAD
<<<<<<< HEAD
//	stack_b = NULL;
//	stack_a = NULL;
//	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return (1);
=======
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
>>>>>>> parent of bb5fd04 (mem errors)
=======
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
>>>>>>> parent of bb5fd04 (mem errors)
	stack_size = get_stack_size(*stack_a);
	print_stack(stack_a);	
	if (stack_size == 3)
	{
		three_num_algor(stack_a);
	}
	else if (stack_size == 2)
		two_num_algor(stack_a);
	else if (stack_size == 4)
		four_num_algor(stack_a, stack_b);
	else if (stack_size == 5)
		five_num_algor(stack_a, stack_b);
	else if (stack_size > 5)
		big_stack_algor(stack_a, stack_b);
<<<<<<< HEAD
<<<<<<< HEAD
	print_stack(stack_a);
//	free_stack(stack_a);
//	free (stack_b);
=======
=======
>>>>>>> parent of bb5fd04 (mem errors)
	free_stack(stack_a);
	free_stack(stack_b);
	free (stack_a);
	free (stack_b);
//	print_stack(stack_a);
<<<<<<< HEAD
>>>>>>> parent of bb5fd04 (mem errors)
=======
>>>>>>> parent of bb5fd04 (mem errors)
	return(0);
}
