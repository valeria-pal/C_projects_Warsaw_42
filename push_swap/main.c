/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:16:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/05/08 13:59:29 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	char	**args;
	int		count;

	a = NULL;
	if (argc < 2)
		return (0);
	args = parse_args(argc, argv, &count);
	if (!args || !is_input_correct(count, args))
	{
		if (argc == 2)
			free_split(args);
		return (1);
	}
	a = insert_data_to_stack(count, args);
	if (argc == 2)
		free_split(args);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	push_swap(&a);
	free_stack(&a);
	return (0);
}
