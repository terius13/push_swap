/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate_oper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:48:02 by ting              #+#    #+#             */
/*   Updated: 2024/03/08 12:16:57 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
//rrr : rra and rrb at the same time.

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *last_element;

	tmp = *stack;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	last_element = tmp->next;
	tmp->next = NULL;
	last_element->next = *stack;
	*stack = last_element;
}
void	re_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	assign_pos(stack_a);
	ft_printf("rra\n");
}

void	re_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	assign_pos(stack_b);
	ft_printf("rrb\n");
}

void	re_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	assign_pos(stack_a);
	reverse_rotate(stack_b);
	assign_pos(stack_b);
	ft_printf("rrr\n");
}
