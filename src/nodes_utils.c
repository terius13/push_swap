/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:13:03 by ting              #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/03/15 12:20:56 by ting             ###   ########.fr       */
=======
/*   Updated: 2024/03/07 11:34:21 by ting             ###   ########.fr       */
>>>>>>> parent of bb5fd04 (mem errors)
=======
/*   Updated: 2024/03/07 11:34:21 by ting             ###   ########.fr       */
>>>>>>> parent of bb5fd04 (mem errors)
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
<<<<<<< HEAD
<<<<<<< HEAD
	new->data = num;
	new->pos = -1;
	new->index = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
=======
=======
>>>>>>> parent of bb5fd04 (mem errors)
	(*new).data = num;
	(*new).pos = -1;
	(*new).index = 0;
	(*new).next = NULL;
<<<<<<< HEAD
>>>>>>> parent of bb5fd04 (mem errors)
=======
>>>>>>> parent of bb5fd04 (mem errors)
	return (new);
}

void	add_node_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*current;

<<<<<<< HEAD
<<<<<<< HEAD
//	current = NULL;
//	current = *stack;
=======
=======
>>>>>>> parent of bb5fd04 (mem errors)
	current = *stack;
>>>>>>> parent of bb5fd04 (mem errors)
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new;
<<<<<<< HEAD
<<<<<<< HEAD
	new->next = NULL;
=======
>>>>>>> parent of bb5fd04 (mem errors)
=======
>>>>>>> parent of bb5fd04 (mem errors)
}
