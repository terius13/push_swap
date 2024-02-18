/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:48:06 by ting              #+#    #+#             */
/*   Updated: 2024/02/18 14:46:08 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.
//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
//rr : ra and rb at the same time.

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *first_element;

	tmp = (*stack)->next;
	first_element = *stack;
	first_element->next = NULL;
	*stack = tmp;
	add_node_bottom(stack, first_element);
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_a_and_b(t_stack **stack_b, t_stack **stack_a)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
