#include "ft_printf.h"

static intmax_t ft_cast_d(t_parsing *parsing, va_list ap)
{
	intmax_t	nbr;

	if (parsing->size == 4 && parsing->letter != 'D')
		nbr = va_arg(ap, intmax_t);
	else if (parsing->size == 3 && parsing->letter != 'D')
		nbr = va_arg(ap, long long);
	else if (parsing->size == 2 || parsing->size == 5 || parsing->letter == 'D')
		nbr = va_arg(ap, long);
	else if (parsing->size == 1 && parsing->letter != 'D')
		nbr = (short)va_arg(ap, int);
	else if (parsing->size == 0 && parsing->letter != 'D')
		nbr = (signed char)va_arg(ap, int);
	else
		nbr = va_arg(ap, int);
	return (nbr);
}

char        *ft_d1(char *str, t_parsing *parsing, int len, intmax_t nbr)
{
    char *res;

    if ((parsing->flag_plus == 1 && nbr >= 0) ||
    (parsing->flag_plus == 1 && parsing->flag_space == 1 && nbr >= 0))
        res = ft_right(str, len + 1, len, '+');
    else if (parsing->flag_space == 1 && nbr >= 0)
        res = ft_right(str, len + 1, len, ' ');
    else if (nbr == 0 && parsing->size != 5)
        res = ft_strdup("");
    else
        res = str;
    return(res);
}

char		*ft_make_str_d(char *str, t_parsing *parsing, intmax_t nbr)
{
    char *res;
    int len;
    
    res = 0;
    len = ft_strlen(str);
    if (len >= parsing->width && len > parsing->precision)
        res = ft_d1(str, parsing, len, nbr);
    else if (len <= parsing->width && len > parsing->precision)
        res = ft_d2(str, parsing, len, nbr);
    else if (len <= parsing->width && len <= parsing->precision &&
        parsing->width >= parsing->precision)
        res = ft_d3(str, parsing, len, nbr);
    else if (len <= parsing->precision && parsing->width < parsing->precision)
        res = ft_d4(str, parsing, len, nbr);
    return (res);
}

void processing_d(t_parsing *parsing, va_list ap)
{
    intmax_t	nbr;
    char *str;
    size_t len;

	nbr = ft_cast_d(parsing, ap);
    str = ft_itoa_max(nbr);
	len = ft_strlen(str);
    if (parsing->width == 0 && parsing->precision == 0 &&
         parsing->flag_plus == 0 && parsing->flag_zero == 0 &&
		 parsing->flag_minus == 0 && parsing->flag_space == 0 && nbr != 0)
         {
             ft_putstr(str);
             parsing->len += len;
         }
    else
        {
            str = ft_make_str_d(str, parsing, nbr);
            ft_putstr(str);
            parsing->len += ft_strlen(str);
        }
}