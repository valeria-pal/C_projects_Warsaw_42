/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:45:46 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/03 16:29:42 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int main()
{
	void *mlx_connection_to_server;
	void *mlx_window_for_mandelbrot;
	
	mlx_connection_to_server = mlx_init();
	if(!mlx_connection_to_server)
	return (1);
	
	mlx_window_for_mandelbrot = mlx_new_window(mlx_connection_to_server, WIDTH, HEIGHT, "Fractal");

	if (!mlx_window_for_mandelbrot)
		return (1);
		mlx_loop(mlx_connection_to_server);
	mlx_destroy_display(mlx_connection_to_server);

	return(0);
}
