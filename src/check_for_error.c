/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:28:52 by ting              #+#    #+#             */
/*   Updated: 2024/03/18 13:19:33 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_for_digit(char **argv)
{
	int			i;
	int			j;
	long		num;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57)
						|| (j == 0 && argv[i][j] == '-'))
				j++;
			else
			{
				return (1);
			}
		}
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
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

	checker_digit = check_for_digit(argv);
	checker_dup = check_for_duplicates(argv);
	if (checker_digit == 1 || checker_dup == 1)
		return (1);
	return (0);
}
