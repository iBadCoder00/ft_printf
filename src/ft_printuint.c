/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:32:49 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:32:49 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunbr_fd(unsigned long n);

int	ft_printuint(unsigned int u_int, t_format format)
{
	int	t_length;

	ignore_flags(&format, " +#");
	t_length = n_formatter(format, u_int, ft_putunbr_fd, uint_length);
	return (t_length);
}

static void	ft_putunbr_fd(unsigned long n)
{
	int	modulo;

	modulo = n % 10;
	n /= 10;
	if (n > 0)
	{
		ft_putunbr_fd(n);
		ft_putchar(modulo + '0');
	}
	else
	{
		ft_putchar(modulo + '0');
	}
}
