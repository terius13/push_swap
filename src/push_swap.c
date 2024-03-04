/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:01 by ting              #+#    #+#             */
/*   Updated: 2024/03/04 14:34:09 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;
	int	stack_size;

	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	stack_a = allocate_stack_a(argc, argv);
	ft_printf("The pos of the first stack: %d\n", (*stack_a)->pos);
	ft_printf("The index of the first stack: %d\n", (*stack_a)->index);
	ft_printf("The index of the second stack: %d\n", (*stack_a)->next->index);
	ft_printf("The index of the third stack: %d\n", (*stack_a)->next->next->index);
	ft_printf("The index of the forth stack: %d\n", (*stack_a)->next->next->next->index);
	ft_printf("The index of the last stack: %d\n", (*stack_a)->next->next->next->next->index);
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
		four_num_algor(stack_a, stack_b);
	else if (stack_size == 5)
		five_num_algor(stack_a, stack_b);
	ft_printf("sorted stack\n");
	print_stack(stack_a);

	//swap test:
//	print_stack(stack_a);
//	ft_printf("Pos before switching: %d\n", (*stack_a)->pos);
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
//	ft_printf("Pos after switching: %d\n", (*stack_a)->pos);
//	print_stack(stack_a);
	return(0);
}
