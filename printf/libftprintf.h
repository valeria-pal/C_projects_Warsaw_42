/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:07:10 by vpaliash          #+#    #+#             */
/*   Updated: 2025/01/17 18:11:56 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int ft_printf(const char * format, ...);
void ft_handle_specifiers(const char specifier);

#endif
