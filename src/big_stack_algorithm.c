/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:30:17 by ting              #+#    #+#             */
/*   Updated: 2024/03/08 15:48:17 by ting             ###   ########.fr       */
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

//I need to reassign the target_pos and the cost for each element in stack_b everytime i push one of the element back to stack_a.
//I need to find the next highest num to the one that im comparing in stack_b
//Before i start assigning target_pos after i shift everything to stack_b, i have to make sure to reassign the elements's new pos in stack_a again, and also after everytime i push an element back to stack_a

void	assign_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	long	target_posi;
	long	target_index;

	tmp_b = (*stack_b);
	while (tmp_b != NULL)
	{
		tmp_a = (*stack_a);
		target_index = 2147483647;
		target_posi = -1;
		while (tmp_a != NULL)
		{
			if ((tmp_a->index > tmp_b->index) && (tmp_a->index < target_index))
			{
				target_index = tmp_a->index;
				target_posi = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
		if (target_posi == -1)
		{
			tmp_a = (*stack_a);
			while (tmp_a != NULL)
			{
				if (tmp_a->index < target_index)
				{
					target_index = tmp_a->index;
					target_posi = tmp_a->pos;
				}
				tmp_a = tmp_a->next;
			}
		}
		tmp_b->target_pos = target_posi;
		tmp_b = tmp_b->next;
	}
}

void	big_stack_algor(t_stack **stack_a, t_stack **stack_b)
{
	push_all_until_three_left(stack_a, stack_b);
	three_num_algor(stack_a);
	ft_printf("Stack_a now after three num sort:\n");
	print_stack(stack_a);
	assign_pos(stack_a);
	assign_pos(stack_b);
	assign_target_pos(stack_a, stack_b);
	ft_printf("Target Pos for first element in stack_b: %d\n", (*stack_b)->target_pos);
	ft_printf("Target Pos for second element in stack_b: %d\n", (*stack_b)->next->target_pos);
	ft_printf("Target Pos for third element in stack_b: %d\n", (*stack_b)->next->next->target_pos);
	ft_printf("Target Pos for fourth element in stack_b: %d\n", (*stack_b)->next->next->next->target_pos);
	/*
	ft_printf("Target Pos for fifth element in stack_b: %d\n", (*stack_b)->next->next->next->next->target_pos);
	ft_printf("Target Pos for six element in stack_b: %d\n", (*stack_b)->next->next->next->next->next->target_pos);
	*/
	get_cost(stack_a, stack_b);
	ft_printf("First ele, Cost_a: %d, Cost_b: %d\n", (*stack_b)->cost_a, (*stack_b)->cost_b);
	ft_printf("Second ele, Cost_a: %d, Cost_b: %d\n", (*stack_b)->next->cost_a, (*stack_b)->next->cost_b);
	ft_printf("Third ele, Cost_a: %d, Cost_b: %d\n", (*stack_b)->next->next->cost_a, (*stack_b)->next->next->cost_b);
	ft_printf("Fourth ele, Cost_a: %d, Cost_b: %d\n", (*stack_b)->next->next->next->cost_a, (*stack_b)->next->next->next->cost_b);
	while (*stack_b != NULL)
	{
	get_cheapest_stack_into_pos(stack_a, stack_b);
	}
	ft_printf("Stack_a now:\n");
	print_stack(stack_a);
	ft_printf("Stack_b now:\n");
	print_stack(stack_b);
}
