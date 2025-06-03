/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:11:47 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/03 18:14:15 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex pixel_to_complex(int x, int y)
{
	t_complex c;
	c.re = MIN_RE + (x * (MAX_RE - MIN_RE) / WIDTH);
	c.im = MIN_IM + (y * (MAX_IM - MIN_IM) / HEIGHT);	
	return c;
}