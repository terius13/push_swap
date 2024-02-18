/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stacka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:45:23 by ting              #+#    #+#             */
/*   Updated: 2024/02/18 21:35:27 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*if_string(char *str)
{
	t_stack	**stack_a;
	char	**strs;
	int	i;
	int	num;

	i = 0;
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_a)
		return (NULL);
	strs = ft_split(str, ' ');
	checker_argv(strs);
	while (strs[i] != NULL)
	{
		num = ft_atoi(strs[i]);
		add_node_bottom(stack_a,new_node(num));
		i++;
	}
	return (*stack_a);
}

t_stack		**allocate_stack_a(int count, char **argv)
{
	t_stack **stack_a;
	int	i;
	int	num;

	i = 1;
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_a)
		return(NULL);
	if (count < 2)
	{
		ft_error_msg();
	}
	else if (count == 2)
	{
		*stack_a = if_string(argv[1]);
	}
	else if (count > 2)
	{
		checker_argv(&argv[1]);
		while (i < count)
		{
			num = ft_atoi(argv[i]);
			add_node_bottom(stack_a, new_node(num));
			i++;
		}
	}
	return (stack_a);
}

