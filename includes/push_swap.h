/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:25:50 by ting              #+#    #+#             */
/*   Updated: 2024/02/09 14:26:27 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int	data;
	struct s_stack	*next;
}	t_stack;

//alloc_stacka.c
t_stack		*if_string(char *str);
t_stack		*allocate_stack_a(int argc, char **argv);

//error_msg.c
void	ft_error_msg(void);

#endif
