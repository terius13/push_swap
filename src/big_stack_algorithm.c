/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:30:17 by ting              #+#    #+#             */
/*   Updated: 2024/03/17 18:22:37 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//To start off, it will push all the int over to stack_b.
//Exceptlast 3 int left stack_a which would be sorted using sort_three function.
//It push over the int starting from the smaller half first e.g. 1-50
//If its from 51-100 then ra until ive pushed 1-50,then it push 51-100 over.

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
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
}

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

void	mv_smallest_num_to_top(t_stack **stack_a)
{
	t_stack	*current;
	int		pos;
	int		stack_size;

	assign_pos(stack_a);
	stack_size = get_stack_size(*stack_a);
	current = (*stack_a);
	if (current->index != 1)
	{
		while (current->index != 1)
		{
			current = current->next;
		}
		pos = current->pos;
		if (pos <= stack_size / 2)
		{
			while (pos > 0)
			{
				rotate_a(stack_a);
				pos--;
			}
		}
		else if (pos > stack_size / 2)
		{
			pos = stack_size - pos;
			while (pos > 0)
			{
				re_rotate_a(stack_a);
				pos--;
			}
		}
	}
}

void	big_stack_algor(t_stack **stack_a, t_stack **stack_b)
{
	push_all_until_three_left(stack_a, stack_b);
	three_num_algor(stack_a);
	while (*stack_b != NULL)
	{
		assign_pos(stack_a);
		assign_pos(stack_b);
		assign_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		get_cheapest_stack_into_pos(stack_a, stack_b);
	}
	mv_smallest_num_to_top(stack_a);
}
