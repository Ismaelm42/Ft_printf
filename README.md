[<img alt="Ft_printf" src="https://img.shields.io/badge/FT_PRINTF-42-blue">](https://github.com/Ismaelm42/Ft_printf)

## ABOUT THE PROJECT

This project has been approached with a constant pursuit of efficiency, consolidating its implementation into **a single file containing only five functions**. These functions have been meticulously crafted to adhere to the rigorous style standards set by school 42.
The assignment involves creating a custom function similar to the printf function in the C programming language, with a focus on enhancing skills related to string manipulation, efficient handling of variable arguments, and output formatting within the context of the C language.
The specified conversions are as follows:

• **%c** Prints a single character.

• **%s** Prints a C string.

• **%p** Prints the memory address of a pointer.

• **%d** Prints a decimal number (base 10).

• **%i** Prints an integer (base 10).

• **%u** Prints an unsigned decimal number (base 10).

• **%x** Prints a hexadecimal number in lowercase (base 16).

• **%X** Prints a hexadecimal number in uppercase (base 16).

• **%%** Prints the percentage symbol.

## BRIEF EXPLANATION OF MY FT_PRINTF'S FUNCTIONS

• [ft_write](https://github.com/Ismaelm42/Ft_printf/blob/main/ft_printf/ft_printf.c#L4): Prints a character or a string to standard output and counts the corresponding number of printed items.

• [ft_convert](https://github.com/Ismaelm42/Ft_printf/blob/main/ft_printf/ft_printf.c#L28): Performs specific conversions for the formats %d, %i, %p, %u, %x, %X. Depending on the data type associated with the format, it carries out necessary conversions to ensure that the value is handled within the bounds of its type.

• [ft_hexabase](https://github.com/Ismaelm42/Ft_printf/blob/main/ft_printf/ft_printf.c#L57): Converts a number to its hexadecimal or decimal representation, depending on the specified format, and then prints the resulting representation to standard output.

• [ft_exec_printf](https://github.com/Ismaelm42/Ft_printf/blob/main/ft_printf/ft_printf.c#L80): Loop that iterates over the format string, printing elements based on detected formats.

• [ft_printf](https://github.com/Ismaelm42/Ft_printf/blob/main/ft_printf/ft_printf.c#L103): Main function that runs the loop.

## HOW TO USE IT?

Clone the repository:

Open your terminal and run the following command to clone the repository:

```sh
git clone git@github.com:Ismaelm42/Ft_printf.git
```

Go into your local repository folder. The project uses a Makefile to manage the build.

```sh
make
```

The make command will compile the project and generate the libftprintf.a library.

**Additional commands:**

```sh
make re
```

Deletes and recompiles the project from scratch.

```sh
make clean
```

Removes object (.o) files generated during compilation.

```sh
make fclean
```

Removes object files and the library (.a).

### USAGE

After compiling the library, you can use it in your projects. Make sure that your source code file includes the corresponding header (ft_printf.h). You can include it in your source code file as follows:

```c
#include "ft_printf.h"
```

When compiling your program, be sure to link it to the libftprintf.a library:

```sh
gcc my_program.c libftprintf.a -o my_program
```

This is a very simple test that you can use and compare with the original printf function if you are starting this project:

```c
#include "ft_printf.h"

int	main(void)
{
	char		c = 'a';
	char		str[] = "Hello World";
	int		n = 123456789;
	unsigned int	u = -123456789;
	void		*ptr = str;

	ft_printf("char = %c\n", c);
	ft_printf("string = %s\n", str);
	ft_printf("integer = %i\n", n);
	ft_printf("decimal = %d\n", n);
	ft_printf("unsigned = %u\n", u);
	ft_printf("pointer = %p\n", ptr);
	ft_printf("hexadecimal = %x\n", n);
	ft_printf("HEXADECIMAL = %X\n", n);
	ft_printf("percentage = %%\n");
	return (0);
}
```

The output should look something like this:

```sh
char = 		a
string = 	Hello World
integer = 	123456789
decimal = 	123456789
unsigned = 	4171510507
pointer	= 	0x7fffae04f5ab
hexadecimal = 	75bcd15
HEXADECIMAL =	75BCD15
percentage = 	%
```

## PROGRAMMING LANGUAGE

<img alt="C-logo" src="https://img.shields.io/badge/C-cdcdcd?style=for-the-badge&logo=Cplusplus&logoColor=2979ff">
