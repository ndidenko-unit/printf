#include "ft_printf.h"

static char        *ft_x1(char *str, t_parsing *parsing, uintmax_t nbr)
{
    char *res;

    if (parsing->flag_sharp == 1 && nbr != 0)
        res = ft_strjoin("0x", str);
    else if (nbr == 0 && (parsing->precision > 0 || parsing->width > 0))
        res = ft_strdup("");
    else
        res = str;
    return(res);
}

static char         *ft_x4(char *str, t_parsing *parsing, int len, uintmax_t nbr)
{
    char *res;

    if (parsing->flag_sharp == 1 && nbr != 0)
    {
        char *tmp;
        res = ft_right(str, parsing->precision, len, '0');
        tmp = res;
        res = ft_strjoin("0x", tmp);
        ft_strdel(&tmp);
    }
    else
        res = ft_right(str, parsing->precision, len, '0');
    return(res);
}

char		*ft_make_str_x(char *str, t_parsing *parsing, uintmax_t nbr)
{
	char *res;
    int len;
    
    res = 0;
    len = ft_strlen(str);
    if (len >= parsing->width && len > parsing->precision)
        res = ft_x1(str, parsing, nbr);
    else if (len <= parsing->width && len > parsing->precision)
        res = ft_x2(str, parsing, len, nbr);
    else if (len <= parsing->width && len <= parsing->precision &&
        parsing->width >= parsing->precision)
        res = ft_x3(str, parsing, len);
    else if (len <= parsing->precision && parsing->width < parsing->precision)
        res = ft_x4(str, parsing, len, nbr);
    return (res);
}
