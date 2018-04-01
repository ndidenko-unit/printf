#include "ft_printf.h"


int ft_validconv(char *conv)
{
 
    while (*conv)
    {
        if (ft_strchr("cCsSpdDioOuUxX%hljz#-+ .0123456789", *conv) != 0)
            conv++;
        else
            return (0);
    }
    return (1);
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