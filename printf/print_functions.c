/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:12:18 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/07 20:18:43 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *counter)
{
	if (!s)
	{
		ft_putstr("(null)", counter);
		return;
	}
	while (*s)
	{
		write(1, s, 1);
		(*counter)++;
		s++;
	}
}

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putnbr_unsigned(unsigned int n, int *counter)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, counter);
	ft_putchar('0' + (n % 10), counter);
}

void	ft_putnbr(int n, int *counter)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', counter);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, counter);
	ft_putchar('0' + (nbr % 10), counter);
}

void	ft_convert_to_hexadecimal(unsigned long decimal, char specifier,
		int *counter)
{
	if (decimal >= 16)
		ft_convert_to_hexadecimal(decimal / 16, specifier, counter);
	if (specifier == 'x')
		ft_putchar("0123456789abcdef"[decimal % 16], counter);
	else if (specifier == 'X')
		ft_putchar("0123456789ABCDEF"[decimal % 16], counter);
}
