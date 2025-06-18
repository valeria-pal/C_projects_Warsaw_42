/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:41:36 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/18 14:09:15 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	parse_fraction(const char *str)
{
	double	fraction;
	double	result;

	fraction = 0.1;
	result = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') * fraction;
		fraction *= 0.1;
		str++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
		result += parse_fraction(++str);
	return (result * sign);
}
