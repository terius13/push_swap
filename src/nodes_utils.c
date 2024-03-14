/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:13:03 by ting              #+#    #+#             */
/*   Updated: 2024/03/14 22:33:20 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = num;
	new->pos = -1;
	new->index = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

void	add_node_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*current;

//	current = NULL;
//	current = *stack;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new;
//	new->next = NULL;
}
