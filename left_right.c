#include "ft_printf.h"

char	*ft_left(char *str, int width, int precision, char c)
{
	char	*snew;
	int		i;

	i = 0;
	snew = ft_strnew(width);
	while (i < width)
	{
		if (i < precision)
			snew[i] = str[i];
		else
			snew[i] = c;
		i++;
	}
	return (snew);
}

char	*ft_right(char *str, int width, int precision, char c)
{
	char	*snew;
	int		i;
	int		j;
	int		len_c;

	i = 0;
	j = 0;
	len_c = width - precision;
	snew = ft_strnew(width);
	while (i < width)
	{
		if (i < len_c)
			snew[i] = c;
		else
			snew[i] = str[j++];
		i++;
	}
	return (snew);
}
