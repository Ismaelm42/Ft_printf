
#include "ft_printf.h"

void	ft_write(int *length, char *str, int c)
{
	int	i;

	if (str == NULL && c == 0)
	{
		write(1, "(null)", 6);
		*length += 6;
	}
	else if (str)
	{
		i = 0;
		while (str[i] != 0)
			i++;
		write(1, str, i);
		*length += i;
	}
	else
	{
		write (1, &c, 1);
		*length += 1;
	}
}

void	ft_convert(int *length, char *str, void *arg)
{
	long				nbr;
	unsigned int		unsigned_nbr;
	unsigned long int	unsigned_long_nbr;

	if (*str == 'd' || *str == 'i')
	{
		nbr = (int)(intptr_t)arg;
		if (nbr < 0)
		{
			ft_write(length, NULL, '-');
			nbr = -nbr;
		}
		ft_hexabase(length, str, nbr, "0123456789abcdef");
	}
	else if (*str == 'u' || *str == 'x' || *str == 'X')
	{
		unsigned_nbr = (unsigned int)(uintptr_t)arg;
		ft_hexabase(length, str, unsigned_nbr, "0123456789abcdef");
	}
	else if (*str == 'p')
	{
		unsigned_long_nbr = (unsigned long int)arg;
		ft_write(length, "0x", 0);
		ft_hexabase(length, str, unsigned_long_nbr, "0123456789abcdef");
	}
}

void	ft_hexabase(int *length, char *str, unsigned long nbr, char *hexa)
{
	unsigned long	base;
	char			c;

	if (*str == 'p' || *str == 'x' || *str == 'X')
		base = 16;
	else
		base = 10;
	if (nbr >= base)
	{
		ft_hexabase(length, str, nbr / base, hexa);
		ft_hexabase(length, str, nbr % base, hexa);
	}
	else
	{
		c = hexa[nbr];
		if (*str == 'X' && (c >= 'a' && c <= 'f'))
			c -= ' ';
		ft_write(length, NULL, c);
	}
}

void	ft_exec_printf(char const *str, va_list arg, int *length)
{
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_write(length, NULL, va_arg(arg, int));
			else if (*str == 's')
				ft_write(length, va_arg(arg, char *), 0);
			else if (*str == 'd' || *str == 'i' || *str == 'p'
				|| *str == 'u' || *str == 'x' || *str == 'X')
				ft_convert(length, (char *)str, va_arg(arg, void *));
			else
				ft_write(length, NULL, *str);
		}
		else
			ft_write(length, NULL, *str);
		str++;
	}
}

int	ft_printf(char const *str, ...)
{
	int			length;
	va_list		arg;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(arg, str);
	length = 0;
	ft_exec_printf(str, arg, &length);
	va_end(arg);
	return (length);
}

// int	main()
// {
// 	char str[] = "hola";
// 	int	 ret;

// 	ret = ft_printf("char = %c\nstring = %s\ndecimal = %d\ninteger = %i\npointer = %p\nunsigned = %u\nhexadecimal = %x\nHEXADECIMAL = %X\n", 'a', str, 84846546545645445, 4252, str, 353536335, 42746274274627, 4274627);
// 	printf("ret ft_printf = %d\n\n\n", ret);
// 	// ret = printf("char = %c\nstring = %s\ndecimal = %d\ninteger = %i\npointer = %p\nunsigned = %u\nhexadecimal = %x\nHEXADECIMAL = %X\n", 'a', str, 15, 4252, str, 353536335, 4274627, 4274627);
// 	// printf("ret original printf = %d\n", ret);
// }
