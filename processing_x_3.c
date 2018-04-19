#include "ft_printf.h"

static char         *ft_x3_2(char *str, t_parsing *parsing, int len)
{
    char *res;
    char *tmp;

	if (parsing->flag_sharp == 1)
	{
	
		tmp = ft_strjoin("0x", ft_right(str, parsing->precision, len, '0'));
		res = ft_right(tmp, parsing->width, parsing->precision + 2, ' ');
	}
	else
	{
		tmp = ft_right(str, parsing->precision, len, '0');
		res = ft_right(tmp, parsing->width, parsing->precision, ' ');
    }
    ft_strdel(&tmp);
	return (res);
}

char         *ft_x3(char *str, t_parsing *parsing, int len)
{
	char *res;
    char *tmp;

	if (parsing->flag_minus == 1 && parsing->flag_sharp == 1)
	{
		tmp = ft_strjoin("0x", ft_right(str, parsing->precision, len, '0'));
		res = ft_left(tmp, parsing->width, parsing->precision + 2, ' ');
	}
	else if (parsing->flag_minus == 1 && parsing->flag_sharp == 0)
	{
		tmp = ft_right(str, parsing->precision, len, '0');
		res = ft_left(tmp, parsing->width, parsing->precision, ' ');
	}
	else
        res = ft_x3_2(str, parsing, len);
    ft_strdel(&tmp);
	return (res);
}