/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:01 by ting              #+#    #+#             */
/*   Updated: 2024/02/18 15:14:34 by ting             ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;

	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
	//swap test:
//	print_stack(stack_a);
//	swap_a(*stack_a);
//	ft_printf("new stack\n");
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
	print_stack(stack_a);
	re_rotate_a(stack_a);
	ft_printf("new stack\n");
	print_stack(stack_a);
	return(0);
}
