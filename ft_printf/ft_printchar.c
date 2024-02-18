#include "ft_printf.h"

int ft_printchar(char c, t_format format)
{

    int printed;

    printed = 0;
    while (1 < format.l_offset--)
        	printed += ft_printf(" ");
    printed += ft_putchar(c);
    while (1 < format.r_offset--)
        	printed += ft_printf(" ");
    return (printed);
}