/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:37:06 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/07 15:12:10 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>



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

static void	ft_putnbr_fd(int n, int fd)//mistake for unsigned
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
static void print_decimal(int n, int fd , char specifier)
{
	char lowercase;
	char uppercase;
	if (specifier == 'x')
	{
	lowercase = "0123456789abcdef"[n];
	write(1,&lowercase,1);
	}
	if (specifier == 'X')
	{
	uppercase = "0123456789ABCDEF"[n];
	write(1,&uppercase,1);
	}
	if (specifier == 'p')
	write(1,&lowercase,1);
}

static void ft_convert_to_hexadecimal(unsigned int decimal,int fd, char specifier)
{	
	unsigned long decimal_nbr;
	decimal_nbr =  decimal;

	if (decimal_nbr >= 16)
	ft_convert_to_hexadecimal(decimal_nbr / 16, fd,specifier);
	print_decimal(decimal_nbr % 16, fd, specifier);
}

static void ft_handle_specifiers(char specifier, int * counter, va_list args)
{
	if (specifier == 's')
	ft_putstr_fd(va_arg(args,char *), 1);
	if (specifier == 'c')
	ft_putchar_fd(va_arg(args, int), 1);
	if (specifier == 'd'  || specifier == 'i')
	ft_putnbr_fd(va_arg(args,int),1);
	if(specifier == 'u')
	ft_putnbr_fd(va_arg(args,unsigned int),1);
	if (specifier == '%')
	write(1, "%",1);
	if(specifier == 'x' || specifier == 'X')
	ft_convert_to_hexadecimal(va_arg(args, int),1,specifier);
	if(specifier == 'p')
	{
		write(1, "0x",2);
		ft_convert_to_hexadecimal(va_arg(args, uintptr_t),1,specifier);
		
	}
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
		int num = 42;  
		int *ptr = &num;
		printf("ORIGINAL PRINTF \n");
		printf("My name is %s and %%, first letter is %c, I have %d years old and %i sisters and some %u, now hexadecimal number is %x and %X, pointer is %p","Alice", 'A', -1,  12,-11,122, 419, ptr);
		printf("\nMY PRINTF \n");
		ft_printf("My name is %s and %%, first letter is %c, I have %d years old and %i sisters and some %u, now hexadecimal number is %x and %X, pointer is %p","Alice", 'A', -1,  12,-11,122, 419, ptr);
		return 0;
	}