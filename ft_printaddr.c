/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:19:24 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:19:24 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddr(void *addr, t_format format)
{
	int	t_length;

	ignore_flags(&format, " +#");
	if (addr == 0)
	{
		while (5 < format.l_offset--)
			t_length += ft_printf(" ");
		t_length += ft_printf("(nil)");
		while (5 < format.r_offset--)
			t_length += ft_printf(" ");
		return (t_length);
	}
	t_length = n_formatter(format, (unsigned long) addr, to_hex, hex_count);
	return (t_length);
}


