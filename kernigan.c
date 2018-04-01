#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* minprintf: минимальный printf с переменным числом аргумент */ 
int ft_printf(char *str, ...)
{
    va_list ap; /* указывает на очередной безымянный аргумент */ 
    //char *p;
    //char *sval;
    //int ival;
    //double dval;
    va_start(ap, str); /* устанавливает ар на 1-й безымянный аргумент */ 
   

    while (*str)
    {
        if (*str != '%') 
        {
            putchar(*str++);
            continue; 
        }
        else
            break;
        // switch (*++p) 
        // {
        //     case 'd':
        //         ival = va_arg(ap, int);
        //         printf ("%d", ival);
        //         break;
        //     case 'f':
        //         dval = va_arg(ap, double);
        //         printf("%f", dval);
        //         break;
        //     case 's':
        //         for (sval = va_arg(ap, char *); *sval; sval++)
        //             putchar(*sval);
        //         break;
        //     default:
        //     putchar(*p);
        //     break; 
        // }
    }
    va_end(ap); /* очистка, когда все сделано */
    return (0);
}

int main()
{
    int i = 6;
    ft_printf("Hello, I have %d friends", i);
    return(0);
}