/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:27:31 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:27:31 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int		plus;
	int		minus;
	int		space;
	int		sharp;
	int		zero;
	int		r_offset;
	int		l_offset;
	int		precision;
	int		precision_dot;
	char	type;

}	t_format;

int		ft_printf(const char *s, ...);
int		ft_printchar(char c, t_format format);
int		ft_putchar(int c);
int		ft_printstr(const char *s, t_format format);
int		ft_printaddr(void *addr, t_format format);
int		ft_printint(long n, t_format format);
int		ft_printuint(unsigned int u_int, t_format format);
int		ft_printhex(long n, t_format format);
int		ft_atoi(const char *string);
int		uint_length(unsigned int n);
int		n_formatter(t_format format, long n,
			void (*print_number)(), int (*nl_count)());
int		get_min_width(t_format format, long n);
int		null_value(long n, t_format format);
int		is_set(char c, char *set);
int		int_length(long int n);
int		hex_count(unsigned long n);
void	ignore_flags(t_format *format, char *s);
void	to_hex(unsigned long n, int mode);
void	ft_putnbr_fd(long int n);
#endif