/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:58:22 by ting              #+#    #+#             */
/*   Updated: 2024/03/17 14:54:46 by ting             ###   ########.fr       */
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
void	assign_pos(t_stack **stack)
{
	int     pos_num;
	t_stack *current;

	current = *stack;
	pos_num = 0;
	while (current)
	{
		current->pos = pos_num;
		pos_num++;
		current = current->next;
	}
}

//The variable stack_size is use to assign the index to the list. It starts assigning from the biggest to smallest number

void	assign_index(t_stack **stack_a)
{
	int	stack_size;
	t_stack	*current;
	long	num;
	t_stack	*highest;

//	current = *stack_a;
	stack_size = get_stack_size(*stack_a);
	while (stack_size > 0)
	{
		current = *stack_a;
		num = -2147483648;
		highest = NULL;
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
