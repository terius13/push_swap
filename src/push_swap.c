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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/03/17 14:28:14 by ting             ###   ########.fr       */
=======
/*   Updated: 2024/03/13 11:55:19 by ting             ###   ########.fr       */
>>>>>>> parent of bb5fd04 (mem errors)
=======
/*   Updated: 2024/03/13 11:55:19 by ting             ###   ########.fr       */
>>>>>>> parent of bb5fd04 (mem errors)
=======
/*   Updated: 2024/03/12 15:19:13 by ting             ###   ########.fr       */
>>>>>>> parent of fa2068b (its works now yaay, left with freeing)
=======
/*   Updated: 2024/03/12 15:19:13 by ting             ###   ########.fr       */
>>>>>>> parent of fa2068b (its works now yaay, left with freeing)
=======
/*   Updated: 2024/03/12 15:19:13 by ting             ###   ########.fr       */
>>>>>>> parent of fa2068b (its works now yaay, left with freeing)
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;
	int	stack_size;

	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
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
<<<<<<< HEAD
	free_stack(stack_a);
	free_stack(stack_b);
	free (stack_a);
	free (stack_b);
//	print_stack(stack_a);
=======
	print_stack(stack_a);
>>>>>>> parent of fa2068b (its works now yaay, left with freeing)
=======
	print_stack(stack_a);
>>>>>>> parent of fa2068b (its works now yaay, left with freeing)
=======
	print_stack(stack_a);
>>>>>>> parent of fa2068b (its works now yaay, left with freeing)
	return(0);
}
