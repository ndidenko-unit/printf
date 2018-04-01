#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

size_t	    ft_search_conversion_letter(char *str)
{
	size_t	i;
	char	*result;
	char    *letter;
	int x;
	x = 0;
	letter = "cCsSpdDioOuUxX%";
	i = 1;
	
	while (str[i])
	{
		if (x == 15)
		{
			x = 0;
			i++;
		}
		if (str[i] != letter[x])
		{
			x++;
			continue;
		}
		if (str[i] == letter[x])
			return(i + 1);
	}
	return (0);
}

void ft_myprint(char *str)
{
	char *conversion;
	size_t result_letter;

	while (*str)
	{
		if (*str == 92 && (*str + 1) == 110)
		{
			ft_putchar('\n');
			*str += 2;
		}
		if (*str != '%') 
		{
			ft_putchar(*str++);
			continue; 
		}
		if (*str == '%')
		{
			result_letter = ft_search_conversion_letter(str);
			conversion = ft_strsub(str, 0, result_letter);
			str += (result_letter);
			ft_putstr("|zamena|");
			continue;
		}
	}
}

void	struct_init(t_parsing *parsing)
{
	parsing->flag_sharp = 0;
	parsing->flag_zero = 0;
	parsing->flag_minus = 0;
	parsing->flag_plus = 0;
	parsing->flag_space = 0;
    parsing->width = -1;
    parsing->precision = -1;
    parsing->size = 0;
    parsing->letter = 0;

	printf("\nflag_sharp = %d, flag_zero = %d, flag_minus = %d, flag_plus = %d, flag_space = %d, width =%d, precision = %d, size = %d, letter = %c", 
	parsing->flag_sharp, parsing->flag_zero, parsing->flag_minus, parsing->flag_plus, parsing->flag_space, parsing->width,parsing->precision, parsing->size, parsing->letter);
}

int ft_printf(char *str, ...)
{
	
	va_list ap; /* указывает на очередной безымянный аргумент */ 
	va_start(ap, str); /* устанавливает ар на 1-й безымянный аргумент */ 
	t_parsing parsing;
	struct_init(&parsing);
	ft_myprint(str);
	
	va_end(ap); /* очистка, когда все сделано */
	return (0);
}

int main()
{
	int i = 6;
	ft_printf("I have %#07d friends %#07x friends\n", i);
	//printf("\nHello, I have % qdqqqq", i);
	//system ("leaks a.out");
	return(0);
}
