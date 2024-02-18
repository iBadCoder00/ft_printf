/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:28:45 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:28:45 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(long n, t_format format)
{
	int	t_length;

	ignore_flags(&format, " +");
	t_length = n_formatter(format, n, to_hex, hex_count);
	return (t_length);
}
