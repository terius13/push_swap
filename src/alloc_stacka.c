/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stacka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:45:23 by ting              #+#    #+#             */
/*   Updated: 2024/03/18 13:58:11 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freestr(char **lst)
{
	char	*n;

	if (!lst)
		return ;
	while (*lst)
	{
		n = *lst;
		lst++;
		free (n);
	}
	*lst = NULL;
}

t_stack	**if_string(char *str)
{
	t_stack	**stack_a;
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(str, ' ');
	if (checker_argv(strs) == 1)
	{
		ft_freestr(strs);
		free (strs);
		ft_error_msg();
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_a)
		return (NULL);
	*stack_a = NULL;
	while (strs[i] != NULL)
	{
		add_node_bottom(stack_a, new_node(ft_atoi(strs[i])));
		i++;
	}
	ft_freestr(strs);
	free (strs);
	return (stack_a);
}

t_stack	**allocate_stack_a(int count, char **argv)
{
	t_stack	**stack_a;
	int		i;
	int		num;

	i = 1;
	if (count == 2)
		stack_a = if_string(argv[1]);
	else if (checker_argv(&argv[1]) == 1)
		ft_error_msg();
	else if (count > 2)
	{
		stack_a = (t_stack **)malloc(sizeof(t_stack *));
		if (!stack_a)
			return (NULL);
		*stack_a = NULL;
		while (i < count)
		{
			num = ft_atoi(argv[i]);
			add_node_bottom(stack_a, new_node(num));
			i++;
		}
	}
	assign_index(stack_a);
	return (stack_a);
}
