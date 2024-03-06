/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_case_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:36:43 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/18 12:52:02 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_low_hex(char c)
{
	if (c > 57)
		c = c + 39;
	write(1, &c, 1);
}

static void	ft_putnbr_hex(int n, int *len)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr > 15)
	{
		ft_putnbr_hex(nbr / 16, len);
		ft_putnbr_hex(nbr % 16, len);
	}
	else
	{
		ft_putchar_low_hex(nbr + '0');
		*len = *len + 1;
	}
}

int	ft_lower_case_hex(void	*arg)
{
	int	count;
	int	*len;

	count = 0;
	len = &count;
	ft_putnbr_hex((int)(intptr_t)arg, len);
	return (*len);
}
