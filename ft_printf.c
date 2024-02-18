#include "ft_printf.h"

int selector(const char *s, va_list *args, t_format format);
int get_format(const char **s, va_list *args);
void set_flag(const char*s, t_format *format);

void init_format(t_format *format)
{
    format->minus = 0;
    format->plus = 0;
    format->precision = 0;
    format->precision_dot = 0;
    format->l_offset = 0;
    format->r_offset = 0;
    format->space = 0;
    format->sharp = 0;
    format->zero = 0;
}

int ft_printf(const char *s, ...)
{
    va_list args;
    size_t p_chars;

    p_chars = 0;
    va_start(args, s);

    while(*s)
    {
        if (*s == '%')
        {
            s++;
            p_chars += get_format(&s, &args);
        }
        else
        {
            ft_putchar(*s);
            p_chars++;
        }
        s++;
    }
    va_end(args);
    return (p_chars);

}
int selector(const char *s, va_list *args, t_format format)
{
    size_t w_chars;

    w_chars = 0;
    if(*(s) == 'c')
        w_chars += ft_printchar(va_arg(*args, int), format);
    else if(*(s) == 's')
        w_chars += ft_printstr(va_arg(*args, char *), format);
    else if(*(s) == 'p')
        w_chars += ft_printaddr(va_arg(*args, void *), format);
    else if(*(s) == 'd' || *(s) == 'i')
        w_chars += ft_printint(va_arg(*args, int), format);
    else if(*(s) == 'u')
        w_chars += ft_printuint(va_arg(*args, unsigned int), format);
    else if(*(s) == 'x' ||*(s) == 'X')
        w_chars += ft_printhex(va_arg(*args, unsigned int), format);
    else if(*(s) == '%')
        w_chars += ft_putchar('%');
    return (w_chars);
}

int get_format(const char **s, va_list *args)
{
    t_format format;

    init_format(&format);
    while (is_set(**s, "0+-# "))
    {
        set_flag(*s, &format);
        (*s)++;
    }
    if(!format.minus)
        format.l_offset = ft_atoi(*s);
    else
        format.r_offset = ft_atoi(*s);
    while (is_set(**s, ".0123456789"))
    {
        if (**s == '.')
        {
            format.precision_dot = 1;
            format.precision = ft_atoi((*s) + 1);
        }
        (*s)++;
    }
    format.type = **s;
    return (selector(*s, args, format));
}

void set_flag(const char *s, t_format *format)
{
    if (*s == '0')
        format->zero = 1;
    else if (*s == '+')
        format->plus = 1;
    else if (*s == '-')
        format->minus = 1;
    else if (*s == '#')
        format->sharp = 1;
    else if (*s == ' ')
        format->space = 1;
}