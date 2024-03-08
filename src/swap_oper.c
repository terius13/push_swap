/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:27:34 by ting              #+#    #+#             */
/*   Updated: 2024/03/08 12:23:07 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Swap the first two elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack *second;

	first = *stack;
	second = (*stack)->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	assign_pos(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	assign_pos(stack_a);
	ft_printf("sb\n");
}

void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	assign_pos(stack_a);
	swap(stack_b);
	assign_pos(stack_b);
	ft_printf("ss\n");
}
