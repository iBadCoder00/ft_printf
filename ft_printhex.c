#include "ft_printf.h"

int ft_printhex(long n, t_format format)
{
   int t_length;

    ignore_flags(&format, " +");
    t_length = n_formatter(format, n, to_hex, hex_count);
    return(t_length);
}

