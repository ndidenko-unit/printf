#include "ft_printf.h"


int ft_validconv(char *conv)
{
    int count;

    count = 1;
    while (*conv++)
    {
        if (ft_strchr("cCsSpdDioOuUxXRZ%hljz#-+ .0123456789", *conv))
            count++;
        else
            return (count);
    }
    return (-1);
}

int ft_validchar(char *str)
{
    if (ft_strchr("cCsSpdDioOuUxXRZ%hljz#-+ .0123456789", *str))
        return (1);
    else
        return (0);
}

int			ft_valid_modifier(char c)
{
	return (ft_strchr("hljz", c) != 0);
}

int			ft_valid_flag(char c)
{
	return (ft_strchr("#0-+ ", c) != 0);
}


int         ft_is_digit(char c)
{
	return (ft_strchr("1234567890", c) != 0);
}
// int main()
// {
//        char *conv = "%#07(d";
//        int res = 0;
//        res = ft_validconv(conv);
//        printf ("res is %i", res);
//        return(0);
// } 