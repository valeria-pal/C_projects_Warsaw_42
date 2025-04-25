/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:08:11 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/24 15:15:15 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	have_no_parameters_to_process(int argc)
{
	return (argc < 2);
}

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_int(char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			return (0);
		value = ft_atoi(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int	have_duplicate(char **argv, int argc)
{
	int i;
	int j;
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_input_correct(int argc, char **argv)
{
	if (have_no_parameters_to_process(argc))
		return (0);
	if (!is_int(argv) || have_duplicate(argv, argc))
	{
		ft_printf(2, "Error\n");
		return (0);
	}
	return (1);
}
