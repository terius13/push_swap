/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:58:22 by ting              #+#    #+#             */
/*   Updated: 2024/03/18 13:22:34 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_num(t_stack *stack_a)
{
	t_stack	*small_num;

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
	t_stack	*current;

	current = *stack_a;
	while (current != NULL)
	{
		ft_printf("%i\n", current->data);
		current = current->next;
	}
}

int	get_stack_size(t_stack *stack_a)
{
	int	i;

	i = 0;
	while ((stack_a) != NULL)
	{
		(stack_a) = (stack_a)->next;
		i++;
	}
	return (i);
}

void	assign_pos(t_stack **stack)
{
	int		pos_num;
	t_stack	*current;

	current = NULL;
	current = *stack;
	pos_num = 0;
	while (current)
	{
		current->pos = pos_num;
		pos_num++;
		current = current->next;
	}
}

void	assign_index(t_stack **stack_a)
{
	int		stack_size;
	t_stack	*current;
	long	num;
	t_stack	*highest;

	stack_size = get_stack_size(*stack_a);
	while (stack_size > 0)
	{
		current = *stack_a;
		num = -2147483648;
		while (current != NULL)
		{
			if ((current->data == num) && (current->index == 0))
				current->index = 1;
			if ((current->data > num) && (current->index == 0))
			{
				num = current->data;
				highest = current;
			}
			current = current->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
		stack_size--;
	}
}
