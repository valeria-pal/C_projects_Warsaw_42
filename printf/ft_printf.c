/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:37:06 by vpaliash          #+#    #+#             */
/*   Updated: 2025/01/22 20:37:44 by vpaliash         ###   ########.fr       */
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

static void ft_handle_specifiers(char specifier, int * counter, va_list args)
{
	if (specifier == 's')
	ft_putstr_fd(va_arg(args,char *), 1);
	else if (specifier == 'c')
	ft_putchar_fd(va_arg(args,char *), 1);
	
	
}

int ft_printf(const char * format, ...)
{
	va_list args;
	int counter;
	
	counter  =   0;

	va_start (args, format);
	
		while(*format != '%' && *format ){
		write(1,format,1);
		format++;
		counter++;
		if (*format == '%')
		{
			format++;
		ft_handle_specifiers(*format, &counter, &args);
		format++;
	
		}
		
	}

	return counter;
}

	int main ()
	{	
		printf("ORIGINAL PRINTF \n");
		printf("My name is %s , I have %d years old ", "Alice" , 15);
		printf("\nMY PRINTF \n");
		ft_printf("My name is %s!",  "Alice");
		return 0;
	}

