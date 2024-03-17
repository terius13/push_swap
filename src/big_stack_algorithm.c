/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:30:17 by ting              #+#    #+#             */
/*   Updated: 2024/03/17 15:57:08 by ting             ###   ########.fr       */
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
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
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

void	mv_smallest_num_to_top(t_stack **stack_a)
{
	t_stack	*current;
	int	pos;
	int	stack_size;

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
//		write(1, "bla\n", 4);
//		print_stack(stack_a);
//		write(1, "bla\n", 4);
//		print_stack(stack_b);
//		write(1, "bla\n", 4);
		assign_pos(stack_a);
		assign_pos(stack_b);
		assign_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		get_cheapest_stack_into_pos(stack_a, stack_b);
	}
	mv_smallest_num_to_top(stack_a);	
}
