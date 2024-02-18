/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:22:17 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:22:17 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, t_format format)
{
	int	printed;

	printed = 0;
	while (1 < format.l_offset--)
		printed += ft_printf(" ");
	printed += ft_putchar(c);
	while (1 < format.r_offset--)
		printed += ft_printf(" ");
	return (printed);
}
