#include "ft_printf.h"

static int print_flags(t_format format, long *n)
{
    int w_chars;

    w_chars = 0;
	if (*n < 0 && format.type != 'X' && format.type != 'x')
	{
		w_chars += ft_printf("-");
		*n *= -1;
	}
	else if (format.plus)
		w_chars += ft_printf("+");
	else if(format.space)
	    w_chars += ft_printf(" ");
	else if((format.sharp && *n != 0) || (format.type == 'p' && *n != 0))
    {
        w_chars += ft_printf("0");
        if (format.type == 'p')
            format.type ='x';
        w_chars += ft_printf("%c", format.type);
    }
    return (w_chars);
}

int n_formatter(t_format format, long n, void (*print_number)(), int (*nl_count)())
{
    int min_w;
    int n_length;
	int printed;
	printed = 0;
    min_w = get_min_width(format, n);
    n_length = nl_count(n);
	if(format.zero)
	{
		printed += print_flags(format, &n);
		while(min_w < format.l_offset--)
                printed += ft_printf("0");
		print_number(n, format.type);
		return (printed + n_length);
	}
    while (min_w < format.l_offset--)
            printed += ft_printf(" ");
	printed += print_flags(format, &n);
    while (n_length < format.precision--)
            printed += ft_printf("0");
    print_number(n, format.type);
    while (min_w < format.r_offset--)
            printed += ft_printf(" ");
    return(printed + n_length);
}

void ignore_flags(t_format *format, char *s)
{
    while (*s)
    {
        if (*s == '+')
            format->plus = 0;
        else if (*s == '-')
            format->minus = 0;
        else if (*s == ' ')
            format->space = 0;
        else if (*s == '#')
            format->sharp = 0;
        else if (*s == '0')
            format->zero = 0;
        s++;
    }
    if ((format->zero && format->minus) || (format->zero && format->precision_dot))
        format->zero = 0;
}

int get_min_width(t_format format, long n)
{   
    int t_length;
    int n_length;

    t_length = 0;
    if(format.type == 'u')
        n_length = uint_length(n);
    else
        n_length = int_length(n);
    if (format.type == 'x' || format.type == 'X' || format.type == 'p')
        n_length = hex_count(n);
    if(format.precision > n_length)
        t_length = n_length + (format.precision - n_length);
    else
        t_length = n_length;
    if (format.plus)
        t_length++;
    else if (n < 0 && format.type != 'x' && format.type != 'X' && format.type != 'u')
        t_length++;
    else if(format.space)
        t_length++;
    else if((format.sharp && n != 0) || format.type == 'p')
        t_length += 2;
    return (t_length);
}