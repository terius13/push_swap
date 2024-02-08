/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stacka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:45:23 by ting              #+#    #+#             */
/*   Updated: 2024/02/08 13:37:54 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*if_string(char *str)
{
	t_stack	*stack_a;
	char	strs;
	int	i;

	i = 0;
	strs = ft_split(str, ' ');
	while (str[i] != NULL)
	{
		ft_lstadd_back(stack_a,ft_lstnew(ft_atoi(str[i])));
	}
	return (stack_a);
}

t_stack		*allocate_stack_a(int argc, char **argv)
{
	t_stack *stack_a;
	int	i;

	i = 1;
	if (argc < 2)
	{
		return (error_msg());
	}
	else if (argc == 2)
	{
		stack_a = if_string(argv[1]);
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			ft_lstadd_back(stack_a, ft_lstnew(argv[i]));
			i++;
		}
	}
	return (stack_a);
}

