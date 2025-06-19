/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:53:09 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/19 15:31:47 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_mlx_data *mlx_data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(mlx_data->mlx_connection, mlx_data->image);
		mlx_destroy_window(mlx_data->mlx_connection, mlx_data->window);
		mlx_destroy_display(mlx_data->mlx_connection);
		free(mlx_data->mlx_connection);
		exit(0);
	}
	return (0);
}

int	handle_close(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx_connection, mlx_data->image);
	mlx_destroy_window(mlx_data->mlx_connection, mlx_data->window);
	mlx_destroy_display(mlx_data->mlx_connection);
	free(mlx_data->mlx_connection);
	exit(0);
	return (0);
}
