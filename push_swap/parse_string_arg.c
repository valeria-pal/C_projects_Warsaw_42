/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:00:53 by vpaliash          #+#    #+#             */
/*   Updated: 2025/05/08 13:59:13 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**parse_args(int argc, char **argv, int *count)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			return (NULL);
		i = 0;
		while (args[i])
			i++;
		*count = i;
	}
	else
	{
		args = argv + 1;
		*count = argc - 1;
	}
	return (args);
}
