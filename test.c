#include <stdio.h>
#include <wchar.h>
#include "ft_printf.h"

char  *ft_strtoupper(char *str)
{
	char *new;
	char *ptr;
	new = ft_strnew(ft_strlen(str));
	ptr = new;
	while(*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*new = *str - 32;
		else
			*new = *str;
		new++;
		str++;
	}
	return (ptr);
}

int main()
{

	int i = 0;
	char *str = "abcdefg5";
	str = ft_strtoupper(str);
	printf("%s", str);


 
	return (0);
}