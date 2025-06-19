/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:45:46 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/19 15:00:54 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal_data	data;

	data.view.min_re = DEFAULT_MIN_RE;
	data.view.max_re = DEFAULT_MAX_RE;
	data.view.min_im = DEFAULT_MIN_IM;
	data.view.max_im = DEFAULT_MAX_IM;
	if (!parse_args(argc, argv, &data))
		return (1);
	data.mlx.mlx_connection = mlx_init();
	data.mlx.window = mlx_new_window(data.mlx.mlx_connection, WIDTH, HEIGHT,
			"Fractol");
	data.mlx.image = mlx_new_image(data.mlx.mlx_connection, WIDTH, HEIGHT);
	data.mlx.pixel_address = mlx_get_data_addr(data.mlx.image,
			&data.mlx.bites_per_pixel, &data.mlx.line_length, &data.mlx.endian);
	mlx_mouse_hook(data.mlx.window, mouse_hook, &data);
	mlx_key_hook(data.mlx.window, handle_key, &data.mlx);
	mlx_hook(data.mlx.window, 17, 0, handle_close, &data.mlx);
	draw_fractal(&data, MAX_ITERATIONS);
	mlx_put_image_to_window(data.mlx.mlx_connection, data.mlx.window,
		data.mlx.image, 0, 0);
	mlx_loop(data.mlx.mlx_connection);
	return (0);
}
