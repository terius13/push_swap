/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:01 by ting              #+#    #+#             */
/*   Updated: 2024/03/13 10:40:13 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;
	int	stack_size;

	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
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
//	print_stack(stack_a);
	return(0);
}
