/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:01 by ting              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/14 13:02:19 by ting             ###   ########.fr       */
=======
/*   Updated: 2024/03/13 15:51:09 by ting             ###   ########.fr       */
>>>>>>> github
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	//if (!*stack)
	//	return ;
	while (*stack)
	{
		tmp = (*stack)->next;
<<<<<<< HEAD
	//	(*stack)->
=======
>>>>>>> github
		free (*stack);
		*stack = NULL;
		*stack = tmp;
	}
	free (stack);
	stack = NULL;
}
/*
void free_stacks(t_stack **stack_a, t_stack **b)
{
	free(stack_b);

}
*/
int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;
	int	stack_size;

	stack_b = NULL;
	stack_a = NULL;
//	stack_b = (t_stack **)malloc(sizeof(t_stack *));
//	if (!stack_b)
//		return (1);
//	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return (1);
	/*
	if (!stack_a)
		free(stack_b)
			(exit);
			*/
	stack_size = get_stack_size(*stack_a);
//	print_stack(stack_a);	
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
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return(0);
}
