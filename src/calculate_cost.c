/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:44:53 by ting              #+#    #+#             */
/*   Updated: 2024/03/08 16:57:57 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	cal_cost_a(t_stack *stack_b, int stack_size_a)
{
	int	cost;

	cost = 0;
	if (stack_b->target_pos > stack_size_a / 2)
	{
		cost = (stack_size_a - stack_b->target_pos) * -1;
	}
	else if (stack_b->target_pos <= stack_size_a / 2)
	{
		cost = stack_b->target_pos;
	}
	return (cost);
}

int	cal_cost_b(t_stack *stack_b, int stack_size_b)
{
	int	cost;

	cost = 0;
	if (stack_b->pos > stack_size_b / 2)
	{
		cost = (stack_size_b - stack_b->pos) * -1;
	}
	else if (stack_b->pos <= stack_size_b / 2)
	{
		cost = stack_b->pos;
	}
	return (cost);
}

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_stack_a;
	t_stack	*tmp_stack_b;
	int		stack_size_a;
	int		stack_size_b;

	tmp_stack_a = (*stack_a);
	tmp_stack_b = (*stack_b);
	stack_size_b = get_stack_size(*stack_b);
	stack_size_a = get_stack_size(*stack_a);
	while ((tmp_stack_b) != NULL)
	{
		tmp_stack_b->cost_a = cal_cost_a(tmp_stack_b, stack_size_a);
		tmp_stack_b->cost_b = cal_cost_b(tmp_stack_b, stack_size_b);
		tmp_stack_b = tmp_stack_b->next;
	}
}
