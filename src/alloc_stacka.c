/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stacka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:45:23 by ting              #+#    #+#             */
/*   Updated: 2024/03/17 13:50:59 by ting             ###   ########.fr       */
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

t_stack		**if_string(char *str)
{
	t_stack	**stack_a;
	char	**strs;
	int	i;
	int	j;
	int	num;
	char	*tmp;

	i = 0;
	j = 0;
	printf("str: %s\n", str);
	strs = ft_split(str, ' ');
	if (!strs)
	{
		free(stack_a);
		return (NULL);
	}
	while (strs[i])
	{
		printf("asdasd %s %p\n", strs[i], strs[i]);
		i++;
	}
	i = 0;
	checker_argv(strs); //will have issues here if error, need to free strs
			    //if checker == 1, free strs, ft_error
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_a)
		return (NULL);
	*stack_a = NULL;
	while (strs[i] != NULL)
	{

		printf("xxxxxxx %p %s\n", strs[i], strs[i]);
//		tmp = strs[i];
		num = ft_atoi(strs[i]);
//		free (strs[i]); //giving invalid free
		add_node_bottom(stack_a,new_node(num));
		i++;
	//	free (strs[i]);
	}
/*	
	while (strs[j] != NULL)
	{
		printf("yyyyyyy %p %s\n", strs[j], strs[j]);
		free(strs[j]);
		j++;
	}
*/	
//	ft_freestr(strs);
//	free (strs);
	return (stack_a);
}	

t_stack		**allocate_stack_a(int count, char **argv)
{
	t_stack **stack_a;
	int	i;
	int	num;

	i = 1;
	num = 0;
//	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_a)
		return(NULL);
	stack_a = NULL;
	if (count < 2)
	{
		ft_error_msg();
	}
	else if (count == 2)
	{
		stack_a = if_string(argv[1]);
	}
	else if (count > 2)
	{
		checker_argv(&argv[1]);
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
	assign_pos(stack_a);
	assign_index(stack_a);
	return (stack_a);
}

