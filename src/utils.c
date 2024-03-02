/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:58:22 by ting              #+#    #+#             */
/*   Updated: 2024/02/29 13:08:27 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_num(t_stack *stack_a)
{
	t_stack *small_num;

	small_num = stack_a;
	while (stack_a->next)
	{
		if (small_num->data > stack_a->next->data)
		{
			small_num = stack_a->next;
		}
		stack_a = stack_a->next;
	}
	return (small_num->pos);
}

void	print_stack(t_stack **stack_a)
{
	t_stack *current = *stack_a;

	while (current != NULL)
	{
		ft_printf("%i\n", current->data);
		current = current->next;
	}
}

int	get_stack_size(t_stack *stack_a)
{
	int     i;

	i = 0;
	while ((stack_a) != NULL)
	{
		(stack_a) = (stack_a)->next;
		i++;
	}
	return (i);
}

//i can modify the stack directly by assign another variable, without changing the original sequence of the original stack
void	assign_pos(t_stack **stack_a)
{
	int     pos_num;
	t_stack *current;

	current = *stack_a;
	pos_num = 0;
	while (current)
	{
		current->pos = pos_num;
		pos_num++;
		current = current->next;
	}
}
