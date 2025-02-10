/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:09:48 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/07 20:18:49 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_pointer(void *ptr, int *counter)
{
	if (ptr == NULL)
		ft_putstr("(nil)", counter);
	else
	{
		ft_putstr("0x", counter);
		ft_convert_to_hexadecimal((uintptr_t)ptr, 'x', counter);
	}
}

void	ft_handle_specifiers(char specifier, int *counter, va_list args)
{
	if (specifier == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (specifier == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (specifier == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), counter);
	else if (specifier == '%')
		ft_putchar('%', counter);
	else if (specifier == 'x' || specifier == 'X')
		ft_convert_to_hexadecimal(va_arg(args, unsigned int), specifier,
			counter);
	else if (specifier == 'p')
		ft_handle_pointer(va_arg(args, void *), counter);
}