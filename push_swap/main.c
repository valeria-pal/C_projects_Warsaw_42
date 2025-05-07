/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:16:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 16:55:18 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;

	if (argc < 2)
		return (0);
	else if (is_input_correct(argc, argv))
	{
		a = insert_data_to_stack(argc, argv);
		if (is_sorted(a))
		{
			ft_printf(1, "already sorted");
			return (0);
		}
		push_swap(&a);
		free_stack(&a);
	}
	return (0);
}
