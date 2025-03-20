/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:08:11 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/20 15:08:12 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	have_no_parameters_to_process(int argc)
{
	if (argc < 3)
		return (1);
	return (0);
}

static int	is_int(char **argv)
{
	int	j;
	int	i;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_atoi(argv[i]) <= INT_MIN || ft_atoi(argv[i]) >= INT_MAX)
				return (0);
			while (argv[i][j])
			{
				if (argv[i][j] <= '0' || argv[i][j] >= '9')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

static int	have_duplicate(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
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
	if (have_duplicate(argv, argc) || !is_int(argv))
	{
		ft_printf(2, "Error");
		return (0);
	}
	else if (have_no_parameters_to_process(argc))
		return (0);

	return (1);
}