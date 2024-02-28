/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:01 by ting              #+#    #+#             */
/*   Updated: 2024/02/28 20:57:43 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack **stack_a)
{
	t_stack	*current = *stack_a;

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

//i can modify the stack directly by assign another variable, without changing the original sequence of the original stack
void	assign_pos(t_stack **stack_a)
{
	int	pos_num;
	t_stack	*current;

	current = *stack_a;
	pos_num = 0;
	while (current)
	{
		current->pos = pos_num;
		pos_num++;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;
	int	stack_size;

	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
	assign_pos(stack_a);
	ft_printf("The smallest num pos: %d\n", find_smallest_num(*stack_a));
	stack_size = get_stack_size(*stack_a);
	ft_printf("Stack Size: %d\n---\n", stack_size);
	if (stack_size == 3)
	{
		three_num_algor(stack_a);
	}
	else if (stack_size == 2)
		two_num_algor(stack_a);
	else if (stack_size == 4)
		four_n_five_num_algor(stack_a, stack_b);
	ft_printf("sorted stack\n");
	print_stack(stack_a);

	//swap test:
//	print_stack(stack_a);
//	swap_a(stack_a);
//	ft_printf("new stack\n");
//	print_stack(stack_a);
	//push test:
//	push_b(stack_a, stack_b);
//	ft_printf("stack_a:\n");
//	print_stack(stack_a);
//	ft_printf("stack_b:\n");
//	print_stack(stack_b);
	//rotate test:
//	print_stack(stack_a);
//	rotate_a(stack_a);
//	ft_printf("rotated stack:\n");
//	print_stack(stack_a);
	//reverse rotate test:
//	print_stack(stack_a);
//	re_rotate_a(stack_a);
//	ft_printf("new stack\n");
//	print_stack(stack_a);
	return(0);
}
