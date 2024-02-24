/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:29:54 by ting              #+#    #+#             */
/*   Updated: 2024/02/24 20:55:51 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Case 1: 2 1 3 -sa> 1 2 3
Case 2: 3 1 2 -ra> 1 2 3
Case 3: 2 3 1 -rra> 1 2 3
Case 4: 1 3 2 -sa> 3 1 2 -ra> 1 2 3
Case 5: 3 2 1 -sa> 2 3 1 -rra> 1 2 3
With every case, I compare top to middle, middle to bottom, and bottom to top.
*/
void	three_num_algor(t_stack **stack_a)
{
	if (((*stack_a)->data > (*stack_a)->next->data) &&
			((*stack_a)->next->data < (*stack_a)->next->next->data) &&
			((*stack_a)->next->next->data > (*stack_a)->data))
		swap_a(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data) &&
			((*stack_a)->next->data < (*stack_a)->next->next->data) &&
			((*stack_a)->next->next->data < (*stack_a)->data))
		rotate_a(stack_a);
	else if (((*stack_a)->data < (*stack_a)->next->data) &&
			((*stack_a)->next->data > (*stack_a)->next->next->data) &&
			((*stack_a)->next->next->data < (*stack_a)->data))
		re_rotate_a(stack_a);
	else if (((*stack_a)->data < (*stack_a)->next->data) &&
			((*stack_a)->next->data > (*stack_a)->next->next->data) &&
			((*stack_a)->next->next->data > (*stack_a)->data))
		swap_a(stack_a);
		rotate_a(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data) &&
			((*stack_a)->next->data > (*stack_a)->next->next->data) &&
			((*stack_a)->next->next->data < (*stack_a)->data))
		swap_a(stack_a);
		re_rotate_a(stack_a);
}
