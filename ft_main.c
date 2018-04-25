#include "ft_printf.h"

size_t	    ft_search_conversion_letter(char *str)
{
	size_t	i;
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
			x++;
		else if (str[i] == letter[x])
			return(i + 1);
	}
	return (0);
}


int ft_myprint(char *str, va_list ap)
{
	char *conv;
	size_t result_letter;
	int len;

	len = 0;
	while (*str)
	{
		if (*str == '%' && (ft_validchar(str + 1) == 0 || *(str + 1) == '\0'))
			str += 1;
		else if (*str != '%') 
		{
			ft_putchar(*str++);
			len += 1;
		}
		else if (*str == '%')
		{
			result_letter = ft_search_conversion_letter(str);
			conv = ft_strsub(str, 0, result_letter);
			if (ft_validconv(conv) == -1)
			{
				str += (result_letter);
				len += ft_print_conv(conv, ap);
			}
			else
				str += ft_validconv(conv);
		}
	}
	return (len);
}

void	ft_struct_init(t_parsing *parsing)
{
	parsing->flag_sharp = 0;
	parsing->flag_zero = 0;
	parsing->flag_minus = 0;
	parsing->flag_plus = 0;
	parsing->flag_space = 0;
    parsing->width = -1;
    parsing->precision = -1;
    parsing->size = -1;
	parsing->letter = 0;
	parsing->len = 0;
}

int ft_printf(char *str, ...)
{
	int len;

	va_list ap; /* указывает на очередной безымянный аргумент */ 
	va_start(ap, str); /* устанавливает ар на 1-й безымянный аргумент */ 
	
	len = ft_myprint(str, ap);
	
	va_end(ap); /* очистка, когда все сделано */
	return (len);
}

// int main()
// {
// 	int x;
// 	int y;

// 	setlocale(LC_ALL, "");
// 	x = ft_printf("%S\n", L"莨莨莨");
// 	y = printf("%S\n", L"莨莨莨");
// 	printf("\nx = %d, y = %d", x, y);
// 	return (0);
// }

// int main()
// {
// 	int i, j = 0;
// 	int x = 9;
// 	i = ft_printf("{%10R}");
// 	printf("\n");
// 	j = printf("{%10R}");
// 	printf("\n i = %d, j = %d\n", i, j);
// 	return(0);
// }