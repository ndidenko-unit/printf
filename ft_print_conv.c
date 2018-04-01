#include "ft_printf.h"


int ft_print_conv(char *conv, va_list ap) // парсинг и печать conv
{
	t_parsing parsing;
	ft_struct_init(&parsing);
	if (ft_validconv(conv) == 0)
	{
			ft_putstr(conv);
			return(ft_strlen(conv));
	}
	ft_parse_flags(conv, &parsing);
	ft_parse_width(conv, &parsing);
	ft_parse_precision(conv, &parsing);
	ft_parse_size(conv, &parsing);
	ft_putstr("|||valid conv|||");
	processing_letter(&parsing, ap);
	// int num = va_arg(ap, int);
	// char *hel = va_arg(ap, char*);
	printf("|\nflag_sharp = %d, flag_zero = %d, flag_minus = %d, flag_plus = %d, flag_space = %d, width =%d, precision = %d, size = %d, letter = %c, len = %d|", 
	parsing.flag_sharp, parsing.flag_zero, parsing.flag_minus, parsing.flag_plus, parsing.flag_space, parsing.width,parsing.precision, parsing.size, parsing.letter, parsing.len);
	return (0);
}

void processing_letter(t_parsing *parsing, va_list ap)
{
	
	if (parsing->letter == 'c' && parsing->size != 2)
		processing_c(parsing, ap);
	else if (parsing->letter == 's' && parsing->size != 2)
		processing_s(parsing, ap);
}

void processing_c(t_parsing *parsing, va_list ap)
{
	char c;
	char *res;
	c = (char)va_arg(ap, int);

	if (parsing->flag_minus == 1 && parsing->width > 0)
	{
		res = ft_left(&c, parsing->width, 1, ' ');
		ft_putstr(res);
		parsing->len += ft_strlen(res);
	}
	else if (parsing->flag_minus == 0 && parsing->width > 0)
	{
		res = ft_right(&c, parsing->width, 1, ' ');
		ft_putstr(res);
		parsing->len += ft_strlen(res);
	}
	else
	{
		ft_putchar(c);
		parsing->len += 1;
	}
}

void processing_s(t_parsing *parsing, va_list ap)
{
	char *str;
	int len;
	str = (char*)va_arg(ap, char*);
	
	len = strlen(str);

}