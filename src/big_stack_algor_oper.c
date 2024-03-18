/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algor_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:55:08 by ting              #+#    #+#             */
/*   Updated: 2024/03/18 12:40:34 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_stack(t_stack **stack_a, t_stack **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	reverse_rotate_both_stack(t_stack **stack_a, t_stack **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		re_rotate_a_and_b(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rotate_stack(t_stack **stack_a, t_stack **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 || *cost_b > 0)
	{
		if (*cost_a > 0)
		{
			rotate_a(stack_a);
			(*cost_a)--;
		}
		if (*cost_b > 0)
		{
			rotate_b(stack_b);
			(*cost_b)--;
		}
	}
}

void	reverse_rotate_stack(t_stack **stack_a, t_stack **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 || *cost_b > 0)
	{
		if (*cost_a > 0)
		{
			re_rotate_a(stack_a);
			(*cost_a)--;
		}
		if (*cost_b > 0)
		{
			re_rotate_b(stack_b);
			(*cost_b)--;
		}
	}
}

void	get_cheapest_stack_into_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if ((ft_nb_abs(tmp->cost_a) + ft_nb_abs(tmp->cost_b)) < cheapest)
		{
			cheapest = ft_nb_abs(tmp->cost_a) + ft_nb_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	if (cost_a < 0 && cost_b < 0)
		reverse_rotate_both_stack(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both_stack(stack_a, stack_b, &cost_a, &cost_b);
	if (cost_a > 0 || cost_b > 0)
		rotate_stack(stack_a, stack_b, &cost_a, &cost_b);
	if (cost_a < 0 || cost_b < 0)
	{
		cost_a = ft_nb_abs(cost_a);
		cost_b = ft_nb_abs(cost_b);
		reverse_rotate_stack(stack_a, stack_b, &cost_a, &cost_b);
	}
	push_a(stack_b, stack_a);
}
