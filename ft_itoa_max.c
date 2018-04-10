#include "ft_printf.h"

static size_t	len_nbr(uintmax_t n, int c)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	if (c == 1)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa_max(intmax_t n)
{
	size_t			len;
	int			c;
	char		*str;
	uintmax_t	un;

	c = 0;
    if (n < 0)
    {
        c = 1;
        un = -1 * n;
    }
    else
        un = n;
	len = len_nbr(un, c);
	str = ft_strnew(len);
	if (!str)
		return (0);
	while (len)
	{
		str[len - 1] = (un % 10) + 48;
		un = un / 10;
		len--;
	}
	if (c == 1)
		str[0] = '-';
	return (str);
}
