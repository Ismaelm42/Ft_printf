/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:12:08 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/23 11:28:44 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_call:
llama a la funcion call. esta se encarga de redigir a una u otra función
dependiendo del caracter que se encuentre importante que sea void ya que
puede entrar cualquier tipo de dato, int, char, char *, etc.
return:
debe devolver un ft_strlen
while:
queda decir que imprima uno a uno los caracteres restantes.
length:
da problemas ya que parece que ejecuta de nuevo la función en vez de
realizar únicamente el retorno del valor. Buscar forma de poder realizar
el ft_strlen de los %... la posible solucion es meter el valor y ejecutar
la función al mismo tiempo. Es decir, eliminar la línea de arriba y usar
solo la comentada. Un poco raro pero parece funcionar
 */

#include "ft_printf.h"

static int	ft_char_counter(char const *str)
{
	write(1, str, 1);
	return (1);
}

static int	ft_length(char const *str, va_list arg, int length)
{
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
				||*str == 'i' || *str == 'u' || *str == 'x' || *str == 'X')
				length = (length + ft_call((va_arg(arg, void *)), str));
			else
				length = length + ft_char_counter(str);
		}
		else
			length = length + ft_char_counter(str);
		str++;
	}
	va_end(arg);
	return (length);
}

int	ft_printf(char const *str, ...)
{
	int		length;
	va_list	arg;

	length = 0;
	va_start(arg, str);
	if (*str == 0)
		return (0);
	length = ft_length(str, arg, length);
	return (length);
}
