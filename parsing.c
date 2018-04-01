#include "ft_printf.h"

int ft_parse_flags(char *conv, t_parsing *parsing)
{
	int count;

	conv += 1; //смещаем указатель с % на след символ
	while (ft_valid_flag(*conv))
	{
		if (*conv == '#')
			parsing->flag_sharp = 1;
		if (*conv == '0')
			parsing->flag_zero = 1;
		if (*conv == '-')
			parsing->flag_minus = 1;
		if (*conv == '+')
			parsing->flag_plus = 1;
		if (*conv == ' ')
			parsing->flag_space = 1;
		conv++;
		count++;
	}
	while (*conv) // парсим букву конверсии
		conv++;
	parsing->letter = *(conv - 1);
	return(count); // возвращаем количество символов, на которые надо сместиться
}

int ft_parse_width(char *conv, t_parsing *parsing)
{
	int count;
	char *ptr;
	char *width;

	count = 0;
	conv += 1;
	while (ft_valid_flag(*conv))
		conv++;
	ptr = conv;
	while (ft_is_digit(*conv))
	{
		count++;
		conv++;
	}
	width = ft_strsub(ptr, 0, count);
	parsing->width = ft_atoi(width);
	return(count); //возвращаем число символов width
}

int ft_parse_precision(char *conv, t_parsing *parsing)
{
	int count;
	char *ptr;
	char *ptr2;
	char *precision;

	count = 0;
	while (*conv)
	{
		if (*conv == '.' && ft_is_digit(*(conv + 1)))
			ptr = conv + 1;
		conv++;
	}
	if (*conv == 0)
		return(0);
	ptr2 = ptr;
	while (ft_is_digit(*ptr))
	{
		ptr++;
		count++;
	}
	precision = ft_strsub(ptr2, 0, count);
	parsing->precision = ft_atoi(precision);
	return(0);
}

int ft_parse_size(char *conv, t_parsing *parsing)
{
	while (ft_valid_modifier(*conv) == 0)
		conv++;
	while (ft_valid_modifier(*conv) == 1)
	{
		if (*conv == 'h' && *(conv + 1) == 'h' && parsing->size < 0)
		{
			parsing->size = 0;
			conv += 2;
		}
		if (*conv == 'h' && *(conv + 1) != 'h' && parsing->size < 1)
			parsing->size = 1;
		if (*conv == 'l' && *(conv + 1) != 'l' && parsing->size < 2)
		{
			parsing->size = 2;
			conv += 2;
		}
		if (*conv == 'l' && *(conv + 1) == 'l' && parsing->size < 3)
			parsing->size = 3;
		if (*conv == 'j' && parsing->size < 4)
			parsing->size = 4;
		if (*conv == 'z')
			parsing->size = 5;
		conv++;
	}
	return(0);
}