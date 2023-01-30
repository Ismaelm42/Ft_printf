/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:10:29 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/23 13:18:41 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	a;
	int	*ptr;

	a = 5;
	ptr = &a;
	printf("Retorno: %d\n\n", printf("\n%p\n", ptr));
	printf("\nRetorno: %d\n", ft_pointer(ptr));
	return (0);
}
