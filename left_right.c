#include "ft_printf.h"

char	*ft_left(char *s, int width, int precision, char c)
{
	char	*snew;
	int		i;

	i = 0;
	snew = ft_strnew(width);
	while (i < width)
	{
		if (i < precision)
			snew[i] = s[i];
		else
			snew[i] = c;
		i++;
	}
	return (snew);
}

char	*ft_right(char *s, int width, int precision, char c)
{
	char	*snew;
	int		i;
	int		j;
	int		ln_c;

	i = 0;
	j = 0;
	ln_c = width - precision;
	snew = ft_strnew(width);
	while (i < width)
	{
		if (i < ln_c)
			snew[i] = c;
		else
			snew[i] = s[j++];
		i++;
	}
	return (snew);
}

// static void    ft_cast(va_list ap, t_spec spec, intmax_t *n)
// {
//     if (spec.size == 0 && spec.type != 'D')
//         (*n = (signed char)va_arg(ap, int));
//     else if (spec.size == 1 && spec.type != 'D')
//         (*n = (short)va_arg(ap, int));
//     else if (spec.size == 2 || spec.size == 5 || spec.type == 'D')
//         (*n = va_arg(ap, long));
//     else if (spec.size == 3 && spec.type != 'D')
//         (*n = va_arg(ap, long long));
//     else if (spec.size == 4 && spec.type != 'D')
//         (*n = va_arg(ap, intmax_t));
//     else
//         (*n = va_arg(ap, int));
// }
