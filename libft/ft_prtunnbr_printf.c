/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtunnbr_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:41:23 by ting              #+#    #+#             */
/*   Updated: 2023/12/20 23:08:47 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_prtunnbr_printf(unsigned int nbr)
{
	unsigned int	n;
	int		count;

	count = 0;
	n = nbr;
	if (n > 9)
		count += ft_prtunnbr_printf(n / 10);
	n = n % 10 + '0';
	count += ft_prtchar_printf(n);
	return (count);
}
