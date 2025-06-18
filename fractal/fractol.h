/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:15:38 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/18 17:33:03 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/ft_printf.h"
#include "minilibx/mlx.h"

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

#define DEFAULT_MAX_RE 1.0
#define DEFAULT_MIN_RE -2.0
#define DEFAULT_MAX_IM 1.2
#define DEFAULT_MIN_IM -1.2

#define MAX_ITERATIONS 1000

typedef struct s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct s_mlx_data
{
	void				*mlx_connection;
	void				*window;
	void				*image;
	char				*pixel_address;
	int					bites_per_pixel;
	int					line_length;
	int					endian;
}						t_mlx_data;

typedef struct s_viewing_window
{
	double				min_re;
	double				max_re;
	double				min_im;
	double				max_im;
}						t_viewing_window;
typedef struct s_fractal_data
{
	t_mlx_data			mlx;
	int					fractal_type;
	t_complex			julia_param;
	t_viewing_window	view;
}						t_fractal_data;

int						parse_args(int argc, char **argv, t_fractal_data *data);

t_complex				pixel_to_complex(int x, int y, t_viewing_window *view);

int						get_color(int iterations, int max_iterations);
void					draw_pixel_on_image(t_mlx_data *mlx_data, int x, int y,
							int color);

void					draw_mandelbrot(t_fractal_data *fractal,
							int max_iterations);
void					draw_julia(t_fractal_data *fractal, int max_iterations);

void					draw_fractal(t_fractal_data *fractal,
							int max_iterations);

int						handle_key(int keycode, t_mlx_data *mlx_data);
int						handle_close(t_mlx_data *mlx_data);

int						mouse_hook(int button, int x, int y, void *param);

#endif