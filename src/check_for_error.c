/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:28:52 by ting              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/14 15:19:35 by ting             ###   ########.fr       */
=======
/*   Updated: 2024/03/02 15:52:46 by ting             ###   ########.fr       */
>>>>>>> parent of bb5fd04 (mem errors)
/*                                                                            */
/* ************************************************************************** */

//In case of error, it must display "Error" followed by a ’\n’ on the standard error.
//Errors include for example: some arguments aren’t integers, some arguments are
//bigger than an integer and/or there are duplicates.
//I will check the string after i ft_split it, so it will be an arg as well.

#include "../includes/push_swap.h"

void	ft_error_msg(void)
{
	perror("Error");
	exit(1);
}

void	check_for_digit(char **argv)
{
	int	i;
	int	j;
	long	int	max_int;
	long	int	min_int;
	long	num;

	i = 0;
	max_int = 2147483647;
	min_int = -2147483648;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57) || (j == 0 && argv[i][j] == '-'))
				j++;
			else
			{
				ft_error_msg();
			}
		}
		num = ft_atol(argv[i]);
		if (num > max_int || num < min_int)
		{
			ft_error_msg();
		}
		i++;
	}
}

void	check_for_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL && argv[i + 1] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				ft_error_msg();
			j++;
		}
		i++;
	}
}

void	checker_argv(char **argv)
{

	check_for_digit(argv);
	check_for_duplicates(argv);
}
