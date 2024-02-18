/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:23 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:29:23 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(long n, t_format format)
{
	int	t_length;

	ignore_flags(&format, "#");
	t_length = n_formatter(format, n, ft_putnbr_fd, int_length);
	return (t_length);
}
