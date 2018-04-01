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

void ft_myprint(char *str, va_list ap)
{
	char *conv;
	size_t result_letter;

	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			ft_putchar('%');
			str += 2;
			continue;
		}
		if (*str != '%') 
		{
			ft_putchar(*str++);
			continue; 
		}
		if (*str == '%' && *(str + 1) != '%')
		{
			result_letter = ft_search_conversion_letter(str);
			conv = ft_strsub(str, 0, result_letter);
			str += (result_letter);
			ft_print_conv(conv, ap);
			continue;
		}
	}
}

void	ft_struct_init(t_parsing *parsing)
{
	parsing->flag_sharp = 0;
	parsing->flag_zero = 0;
	parsing->flag_minus = 0;
	parsing->flag_plus = 0;
	parsing->flag_space = 0;
    parsing->width = 0;
    parsing->precision = 0;
    parsing->size = -1;
	parsing->letter = 0;
	parsing->len = 0;
}

int ft_printf(char *str, ...)
{
	
	va_list ap; /* указывает на очередной безымянный аргумент */ 
	va_start(ap, str); /* устанавливает ар на 1-й безымянный аргумент */ 
	
	ft_myprint(str, ap);
	
	va_end(ap); /* очистка, когда все сделано */
	return (0);
}

int main()
{
	char *str = "AxaxaxaxaxaxaxaxA";
	ft_printf("I have 5  %12s\n", str);
	//printf("\nHello, I have % qdqqqq", i);
	//system ("leaks a.out");
	return(0);
}
