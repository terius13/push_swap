/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:01 by ting              #+#    #+#             */
/*   Updated: 2024/03/18 20:38:56 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_if_stack_is_sorted(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	choose_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	if (stack_size == 2)
		two_num_algor(stack_a);
	else if (stack_size == 3)
		three_num_algor(stack_a);
	else if (stack_size == 4)
		four_num_algor(stack_a, stack_b);
	else if (stack_size == 5)
		five_num_algor(stack_a, stack_b);
	else if (stack_size > 5)
		big_stack_algor(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		stack_size;

	if (argc < 2)
		return (1);
	stack_a = allocate_stack_a(argc, argv);
	if (!check_if_stack_is_sorted(stack_a))
	{
		free_stack(stack_a);
		free (stack_a);
		return (0);
	}
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return (1);
	*stack_b = NULL;
	choose_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free (stack_a);
	free (stack_b);
	return (0);
}
