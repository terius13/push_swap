/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:30:17 by ting              #+#    #+#             */
/*   Updated: 2024/03/05 11:50:25 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * To start of the algor, it will push all the int over to stack_b except the last three int left in stack_a which would then be sorted using sort_three function.
 * I will push over the int starting from the smaller half of the stack first e.g. 1 to 50, if it is from 51 to 100 then i will ra until ive pushed 1 to 50, then i will push 51 to 100 over.
*/

void	push_all_until_three_left(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;

	pushed = 0;
	stack_size = get_stack_size(*stack_a);
	while (pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
		{
			rotate_a(stack_a);
		}
	}
	ft_printf("--- push first half ---\n");
	ft_printf("stack_a now:\n");
	print_stack(stack_a);
	ft_printf("stack_b now:\n");
	print_stack(stack_b);
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
	ft_printf("--- push second half --- \n");
	ft_printf("stack_a now:\n");
	print_stack(stack_a);
	ft_printf("stack_b now:\n");
	print_stack(stack_b);
}

void	find_cost_to_stack_a()
{

}

void	big_stack_algor(t_stack **stack_a, t_stack **stack_b)
{
	push_all_until_three_left(stack_a, stack_b);
	three_num_algor(stack_a);
}
