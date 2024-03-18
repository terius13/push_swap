/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:29:54 by ting              #+#    #+#             */
/*   Updated: 2024/03/18 20:27:37 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_num_algor(t_stack **stack_a)
{
	int	first;
	int	second;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	if (first > second)
		swap_a(stack_a);
}

/*
three_num_algor:
Case 1: 2 1 3 -sa> 1 2 3
Case 2: 3 1 2 -ra> 1 2 3
Case 3: 2 3 1 -rra> 1 2 3
Case 4: 1 3 2 -sa> 3 1 2 -ra> 1 2 3
Case 5: 3 2 1 -sa> 2 3 1 -rra> 1 2 3
With every case, I compare top to middle, middle to bottom, and bottom to top.
*/

void	three_num_algor(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if ((first > second) && (second < third) && (third > first))
		swap_a(stack_a);
	else if ((first > second) && (second < third) && (third < first))
		rotate_a(stack_a);
	else if ((first < second) && (second > third) && (third < first))
		re_rotate_a(stack_a);
	else if ((first < second) && (second > third) && (third > first))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((first > second) && (second > third) && (third < first))
	{
		swap_a(stack_a);
		re_rotate_a(stack_a);
	}
}

void	four_num_algor(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	small_num_pos;

	assign_pos(stack_a);
	stack_size = get_stack_size(*stack_a);
	small_num_pos = find_smallest_num(*stack_a);
	if (small_num_pos < (stack_size / 2))
	{
		while (small_num_pos-- > 0)
			rotate_a(stack_a);
	}
	else if (small_num_pos >= (stack_size / 2))
	{
		small_num_pos = stack_size - small_num_pos;
		while (small_num_pos-- > 0)
			re_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	three_num_algor(stack_a);
	push_a(stack_b, stack_a);
}

void	five_num_algor(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	small_num_pos;
	int	count;

	count = 2;
	assign_pos(stack_a);
	while (count > 0)
	{
		small_num_pos = find_smallest_num(*stack_a);
		stack_size = get_stack_size(*stack_a);
		if (small_num_pos < (stack_size / 2))
			while (small_num_pos-- > 0)
				rotate_a(stack_a);
		else if (small_num_pos >= (stack_size / 2))
		{
			small_num_pos = stack_size - small_num_pos;
			while (small_num_pos-- > 0)
				re_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		count--;
	}
	three_num_algor(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}
