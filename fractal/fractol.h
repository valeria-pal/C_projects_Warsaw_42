/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:15:38 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/03 18:14:31 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "minilibx/mlx.h"

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>   
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 600

#define MAX_RE 1.0
#define MIN_RE -2.0
#define MAX_IM 1.2
#define MIN_IM -1.2

typedef struct s_complex {
	double re;
	double im;
}	t_complex;

t_complex pixel_to_complex(int x, int y);
int get_color(int iterations, int max_iterations);
int	mandelbrot_iterations(int x, int y, int max_iterations);

#endif