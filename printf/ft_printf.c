/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:37:06 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/07 16:46:23 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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


static void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *counter )
{
	
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd, counter);
	 ft_putchar_fd('0' + (n % 10), fd);
	(*counter)++;
}

static void	ft_putnbr_fd(int n, int fd, int *counter) 
{
    long	nbr;

    nbr = n;
    if (nbr < 0)
    {
        write(fd, "-", 1);
        nbr = -nbr;
        (*counter)++;
    }
    if (nbr >= 10)
        ft_putnbr_fd(nbr / 10, fd, counter);
    ft_putchar_fd('0' + (nbr % 10), fd);
    (*counter)++;
}


static void ft_convert_to_hexadecimal(unsigned long decimal,int fd, char specifier, int* counter)
{	
	if (decimal >= 16)
	ft_convert_to_hexadecimal(decimal / 16, fd,specifier, counter);
	if (specifier == 'x')
	ft_putchar_fd("0123456789abcdef"[decimal%16],fd);
	else if (specifier == 'X')
	ft_putchar_fd("0123456789ABCDEF"[decimal%16],fd);
	(*counter)++;
}

static void ft_handle_specifiers(char specifier, int * counter, va_list args)
{
	if (specifier == 's')
	{
	char *str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
	*counter += ft_strlen(str);
}
	else if (specifier == 'c')
	{
	ft_putchar_fd(va_arg(args, int), 1);
	(*counter)++;
	}
	else if (specifier == 'd'  || specifier == 'i')
	{
		int decimal = va_arg(args,int);
	ft_putnbr_fd(decimal ,1, counter);
	}
	else if(specifier == 'u')
	ft_putnbr_unsigned_fd(va_arg(args,unsigned int),1, counter);
	
	else if (specifier == '%')
	{
	write(1, "%",1);
	(*counter)++;
	}
	else if(specifier == 'x' || specifier == 'X')
	
	ft_convert_to_hexadecimal(va_arg(args,unsigned int),1,specifier, counter);
	
	else if(specifier == 'p')
	{
		write(1, "0x",2);
		ft_convert_to_hexadecimal(va_arg(args, uintptr_t),1,'x', counter);
		*counter += 2;
	
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
		int counter1;
		int counter2;
		printf("ORIGINAL PRINTF \n");
		counter1 = printf("My name is %s and %%, first letter is %c, I have %d years old and %i sisters and some %u, now hexadecimal number is %x and %X, pointer is %p","Alice", 'A', -1,  12,-11,122, 419, ptr);
		printf("\nMY PRINTF \n");
		counter2 = ft_printf("My name is %s and %%, first letter is %c, I have %d years old and %i sisters and some %u, now hexadecimal number is %x and %X, pointer is %p","Alice", 'A', -1,  12,-11,122, 419, ptr);

		printf("\nCounter1: %d  and counter2: %d ", counter1,counter2);
		return 0;
	}