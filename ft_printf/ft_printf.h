#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_write(int *length, char *str, int c);
void	ft_cast(int *length, char *str, void *arg);
void	ft_hexabase(int *length, char *str, unsigned long nbr, char *hexa);
void	ft_exec_printf(char const *str, va_list arg, int *length);
int		ft_printf(char const *str, ...);

#endif
