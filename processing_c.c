#include "ft_printf.h"

void processing_c(t_parsing *parsing, va_list ap)
{
	char c;
	char *res;
	c = (char)va_arg(ap, int);

	if (parsing->width > 0 && c != 0)
	{
		if (parsing->flag_minus == 1)
			res = ft_left(&c, parsing->width, 1, ' ');
		else if (parsing->flag_minus == 0)
			res = ft_right(&c, parsing->width, 1, ' ');
		ft_putstr(res);
		parsing->len += ft_strlen(res);
	}
	else if (parsing->width > 0 && c == 0)
	{
		parsing->len += processing_c_0(parsing->width);
	}
	else
	{
		ft_putchar(c);
		parsing->len += 1;
	}
}

int processing_c_0(int width)
{
	int i;

	i = width;
	while (i != 1)
	{
		write(1, " ", 1);
		i--;
	}
	write(1, "\0", 1);
	return(width);
}
