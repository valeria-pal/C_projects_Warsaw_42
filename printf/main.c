/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:10:39 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/07 20:18:37 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
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