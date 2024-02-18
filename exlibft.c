/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exlibft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:11:34 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:11:34 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long int n)
{
	int	modulo;

	modulo = n % 10;
	n /= 10;
	if (n < 0 || modulo < 0)
	{
		ft_printf("-");
		modulo *= -1;
		n *= -1;
	}
	if (n > 0)
	{
		ft_putnbr_fd(n);
		ft_printf("%c", modulo + '0');
	}
	else
	{
		ft_printf("%c", modulo + '0');
	}
}

int	ft_atoi(const char *string)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	if (!string)
		return (0);
	while ((*string >= 9 && *string <= 13) || *string == 32)
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign *= -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		number = number * 10 + *string - '0';
		string++;
	}
	return (number * sign);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
