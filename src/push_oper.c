/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:39:50 by ting              #+#    #+#             */
/*   Updated: 2024/02/17 18:15:36 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.

#include "../includes/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp; 
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
