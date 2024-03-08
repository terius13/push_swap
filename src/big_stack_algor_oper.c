/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algor_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:55:08 by ting              #+#    #+#             */
/*   Updated: 2024/03/08 12:21:20 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = (*stack_b)->cost_a;
	cost_b = (*stack_b)->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rotate_a_and_b(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	(*stack_b)->cost_a = cost_a;
	(*stack_b)->cost_b = cost_b;
}

void	reverse_rotate_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = (*stack_b)->cost_a * -1;
	cost_b = (*stack_b)->cost_b * -1;
	while (cost_a > 0 && cost_b > 0)
	{
		re_rotate_a_and_b(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	(*stack_b)->cost_a = cost_a;
	(*stack_b)->cost_b = cost_b;
}

void	rotate_stack(t_stack **stack)
{

}

void	reverse_rotate_stack(t_stack **stack)
{

}

void	get_stack_into_pos(t_stack **stack_a, t_stack **stack_b)
{

}
