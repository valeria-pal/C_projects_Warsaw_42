/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:07:10 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/07 20:19:41 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(char *s, int *counter);
void	ft_putchar(char c, int *counter);
void	ft_putnbr_unsigned(unsigned int n, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_convert_to_hexadecimal(unsigned long decimal, char specifier,
			int *counter);
void	ft_handle_specifiers(char specifier, int *counter, va_list args);

#endif
