#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <wchar.h>

typedef enum    e_size
{
	no_size = -1,
    hh = 0,
    h = 1,
    l = 2,
    ll = 3,
    j = 4,
    z = 5
}	t_size;

typedef struct	s_parsing
{
	int		flag_sharp;
	int 	flag_zero;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
    int     width;
    int     precision;
    t_size     size;
    char    letter;
    int     len;
} 				t_parsing;

int ft_print_conv(char *conv, va_list ap);

size_t	    ft_search_conversion_letter(char *str);
void ft_myprint(char *str, va_list ap);
void	ft_struct_init(t_parsing *parsing);
int ft_printf(char *str, ...);
int ft_validconv(char *conv);
int			ft_valid_flag(const char c);
int			ft_valid_modifier(char c);
int         ft_is_digit(char c);
int ft_parse_flags(char *conv, t_parsing *parsing);
int ft_parse_width(char *conv, t_parsing *parsing);
int ft_parse_precision(char *conv, t_parsing *parsing);
int ft_parse_size(char *conv, t_parsing *parsing);

void processing_c(t_parsing *parsing, va_list ap);
void processing_letter(t_parsing *parsing, va_list ap);
void processing_s(t_parsing *parsing, va_list ap);

char	*ft_left(char *s, int width, int precision, char c);
char	*ft_right(char *s, int width, int precision, char c);

#endif