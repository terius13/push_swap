/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algor_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:55:08 by ting              #+#    #+#             */
/*   Updated: 2024/03/13 10:36:46 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_stack(t_stack **stack_a, t_stack **stack_b, int *cost__a, int *cost__b)
{
	while (*cost__a > 0 && *cost__b > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		(*cost__a)--;
		(*cost__b)--;
	}
}

void	reverse_rotate_both_stack(t_stack **stack_a, t_stack **stack_b, int *cost__a, int *cost__b)
{
	while (*cost__a > 0 && *cost__b > 0)
	{
		re_rotate_a_and_b(stack_a, stack_b);
		(*cost__a)--;
		(*cost__b)--;
	}
}

void	rotate_stack(t_stack **stack_a, t_stack **stack_b, int *cost__a, int *cost__b)
{
	while (*cost__a > 0 || *cost__b > 0)
	{
		if (*cost__a > 0)
		{
			rotate_a(stack_a);
			(*cost__a)--;
		}
		if (*cost__b > 0)
		{
			rotate_b(stack_b);
			(*cost__b)--;
		}
	}
}

void	reverse_rotate_stack(t_stack **stack_a, t_stack **stack_b, int *cost__a, int *cost__b)
{
	while (*cost__a > 0 || *cost__b > 0)
	{
		if (*cost__a > 0)
		{
			re_rotate_a(stack_a);
			(*cost__a)--;
		}
		if (*cost__b > 0)
		{
			re_rotate_b(stack_b);
			(*cost__b)--;
		}
	}
}

void	get_cheapest_stack_into_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int	cheapest;
	int	cost__a;
	int	cost__b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if ((ft_nb_abs(tmp->cost_a) + ft_nb_abs(tmp->cost_b)) < cheapest)
		{
			cheapest = ft_nb_abs(tmp->cost_a) + ft_nb_abs(tmp->cost_b);
			cost__a = tmp->cost_a;
			cost__b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	if (cost__a < 0 && cost__b < 0)
	{
		reverse_rotate_both_stack(stack_a, stack_b, &cost__a, &cost__b);
	}
	else if (cost__a > 0 && cost__b > 0)
	{
		rotate_both_stack(stack_a, stack_b, &cost__a, &cost__b);
	}
	if (cost__a > 0 || cost__b > 0)
		rotate_stack(stack_a, stack_b, &cost__a, &cost__b);
	if (cost__a < 0 || cost__b < 0)
	{
		cost__a = ft_nb_abs(cost__a);
		cost__b = ft_nb_abs(cost__b);
		reverse_rotate_stack(stack_a, stack_b, &cost__a, &cost__b);
	}
	push_a(stack_b, stack_a);
}
