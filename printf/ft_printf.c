/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:37:06 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/04 13:26:03 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	print_nbr(int n, int fd)
{
	char	digit;

	digit = "0123456789"[n];
	write(fd, &digit, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	print_nbr(nbr % 10, fd);
}

static void ft_handle_specifiers(char specifier, int * counter, va_list args)
{
	if (specifier == 's')
	ft_putstr_fd(va_arg(args,char *), 1);
	if (specifier == 'c')
	ft_putchar_fd(va_arg(args,int ), 1);
	if (specifier == 'd'  || specifier == 'i')
	ft_putnbr_fd(va_arg(args,int),1);	
}

int ft_printf(const char * format, ...)
{
	va_list args;
	int counter;
	
	counter  =   0;

	va_start (args,format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_handle_specifiers(*format, &counter, args);
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}

	va_end(args);
	return counter;
}

	int main ()
	{	
		printf("ORIGINAL PRINTF \n");
		printf("My name is %s , first letter is %c, I have %d years old and %i sisters",  "Alice", 'A', -1, 3);
		printf("\nMY PRINTF \n");
		ft_printf("My name is %s , first letter is %c, I have %d years old and %i sisters",  "Alice", 'A', -1,3);
		return 0;
	}