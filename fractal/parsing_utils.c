/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:44:11 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/18 19:01:27 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_printf("Use please:\n");
	ft_printf(" ./fractol mandelbrot\n");
	ft_printf(" ./fractol julia <real part> <imaginary part>\n");
}
static void	julia_warning_if_needed(t_complex c)
{
	if (c.re < -2 || c.re > 2 || c.im < -2 || c.im > 2)
	{
		ft_printf(" Julia parameters are outside the typical range [-2.0, 2.0]\n",
			c.re, c.im);
	}
}
int	parse_args(int argc, char **argv, t_fractal_data *data)
{
	if (argc < 2)
	{
		print_usage();
		return (0);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractal_type = 0;
		return (1);
	}
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		data->fractal_type = 1;
		data->julia_param.re = ft_atof(argv[2]);
		data->julia_param.im = ft_atof(argv[3]);
		julia_warning_if_needed(data->julia_param);
		return (1);
	}
	else
	{
		ft_printf("Invalid parameters.\n");
		print_usage();
		return (0);
	}
}
