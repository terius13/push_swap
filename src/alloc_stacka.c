/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stacka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:45:23 by ting              #+#    #+#             */
/*   Updated: 2024/02/16 14:05:36 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*if_string(char *str)
{
	t_stack	**stack_a = NULL;
	char	**strs;
	int	i;
	int	num;

	i = 0;
	strs = ft_split(str, ' ');
	while (strs[i] != NULL)
	{
		num = ft_atoi(strs[i]);
		add_node_bottom(stack_a,new_node(num));
		i++;
	}
	return (*stack_a);
}

t_stack		*allocate_stack_a(int argc, char **argv)
{
	t_stack **stack_a = NULL;
	int	i;
	int	num;

	i = 1;
	if (argc < 2)
	{
		ft_error_msg();
	}
	else if (argc == 2)
	{
		*stack_a = if_string(argv[1]);
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			add_node_bottom(stack_a, new_node(num));
			i++;
		}
	}
	return (*stack_a);
}

