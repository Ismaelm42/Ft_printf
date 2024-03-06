/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:36:32 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/18 13:23:27 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
hay que utilizar size_t o long por si el numero es muy largo. mirar el signo del numero.
*/

#include "ft_printf.h"

static void	ft_putnbr_decimal(int n, int *len)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -nbr;
		*len = *len + 1;
	}
	if (nbr > 9)
	{
		ft_putnbr_decimal(nbr / 10, len);
		ft_putnbr_decimal(nbr % 10, len);
	}
	else
	{
		ft_putchar_fd(nbr + '0', 1);
		*len = *len + 1;
	}
}

int	ft_decimal(void *arg)
{
	int	count;
	int	*len;

	count = 0;
	len = &count;
	ft_putnbr_decimal((int)(intptr_t)arg, len);
	return (*len);
}
