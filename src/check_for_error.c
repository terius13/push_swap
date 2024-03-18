/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:28:52 by ting              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 12:22:14 by ting             ###   ########.fr       */
=======
/*   Updated: 2024/03/17 17:08:39 by ting             ###   ########.fr       */
>>>>>>> parent of b725697 (now need to refactor functions)
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

int	check_for_digit(char **argv)
{
<<<<<<< HEAD
	int			i;
	int			j;
	long		num;
=======
	int	i;
	int	j;
	long	int	max_int;
	long	int	min_int;
	long	num;
>>>>>>> parent of b725697 (now need to refactor functions)

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57) || (j == 0 && argv[i][j] == '-'))
				j++;
			else
			{
				return (1);
			}
		}
		num = ft_atol(argv[i]);
<<<<<<< HEAD
		if (num > 2147483647 || num < -2147483648)
=======
		if (num > max_int || num < min_int)
		{
>>>>>>> parent of b725697 (now need to refactor functions)
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_for_duplicates(char **argv)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checker_argv(char **argv)
{
	int	checker_digit;
	int	checker_dup;

	checker_digit = 0;
	checker_dup = 0;
	checker_digit = check_for_digit(argv);
	checker_dup = check_for_duplicates(argv);
	if (checker_digit == 1 || checker_dup == 1)
		return (1);
	return (0);
}
